/// Source : https://leetcode-cn.com/problems/you-le-yuan-de-you-lan-ji-hua/
/// Author : liuyubobobo
/// Time   : 2020-05-04

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Greedy + Combining Algorithms
/// Time Complexity: O(V * E)
/// Space Complexity: O(V + E)
class Solution {

private:
    const int BACKUP_SZ = 3;

public:
    int maxWeight(vector<vector<int>>& edges, vector<int>& value) {

        int n = value.size();
        int LIMIT = sqrt(n);

        vector<unordered_set<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);

        sort(edges.begin(), edges.end(), [value](const vector<int>& e1, const vector<int>& e2){
            return value[e1[0]] + value[e1[1]] > value[e2[0]] + value[e2[1]];
        });

        int res = 0;
        for(int v = 0; v < n; v ++){

            if(g[v].size() <= LIMIT){

                vector<vector<int>> tedges;
                for(int x: g[v])
                    for(int y: g[v])
                        if(x < y && g[x].count(y)) tedges.push_back({x, y});
                sort(tedges.begin(), tedges.end(), [value](const vector<int>& e1, const vector<int>& e2){
                    return value[e1[0]] + value[e1[1]] > value[e2[0]] + value[e2[1]];
                });
                res = max(res, test(g, v, tedges, value));
            }
            else{
                res = max(res, test(g, v, edges, value));
            }
        }
        return res;
    }

private:
    int test(vector<unordered_set<int>>& g,
             int v, const vector<vector<int>>& edges, const vector<int>& value){

        vector<vector<int>> backup;
        int res = 0, minIndex = -1;
        for(const vector<int>& e: edges)
            if(g[v].count(e[0]) && g[v].count(e[1])){

                res = max(res, value[v] + value[e[0]] + value[e[1]]);

                for(const vector<int>& backupe: backup)
                    res = max(res, value[v] + calc(value, e[0], e[1], backupe[0], backupe[1]));

                if(backup.size() < BACKUP_SZ) backup.push_back(e);
                else backup[minIndex] = e;

                minIndex = 0;
                for(int i = 1; i < backup.size(); i ++)
                    if(value[backup[i][0]] + value[backup[i][1]] < value[backup[minIndex][0]] + value[backup[minIndex][1]])
                        minIndex = i;
            }
        return res;
    }

    int calc(const vector<int>& value, int a, int b, int c, int d){

        int res = value[a] + value[b];
        if(c != a && c != b) res += value[c];
        if(d != a && d != b) res += value[d];
        return res;
    }
};


int main() {

    vector<vector<int>> edges1 = {{0,1},{1,2},{0,2}};
    vector<int> value1 = {1, 2, 3};
    cout << Solution().maxWeight(edges1, value1) << endl;
    // 6

    vector<vector<int>> edges2 = {{0,2},{2,1}};
    vector<int> value2 = {1, 2, 5};
    cout << Solution().maxWeight(edges2, value2) << endl;
    // 0

    vector<vector<int>> edges3 = {{0,1},{0,2},{0,3},{0,4},{0,5},{1,3},{2,4},{2,5},{3,4},{3,5},{4,5}};
    vector<int> value3 = {7,8,6,8,9,7};
    cout << Solution().maxWeight(edges3, value3) << endl;
    // 39

    vector<vector<int>> edges4 = {{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9}};
    vector<int> value4 = {4441,8166,4493,3043,7988,2504,2328,1730,8841,2613};
    cout << Solution().maxWeight(edges4, value4) << endl;
    // 0

    return 0;
}