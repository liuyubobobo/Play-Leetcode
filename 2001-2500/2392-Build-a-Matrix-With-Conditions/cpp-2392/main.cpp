/// Source : https://leetcode.com/problems/build-a-matrix-with-conditions/
/// Author : liuyubobobo
/// Time   : 2022-08-27

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;


/// Topological Sort
/// Time Complexity: O(k + |rowConstions| + |colConditions|)
/// Space Complexity: O(k + |rowConstions| + |colConditions|)
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<set<int>> rowG(k + 1), colG(k + 1);
        for(const vector<int>& rc: rowConditions){
            int u = rc[0], v = rc[1];
            rowG[u].insert(v);
        }
        for(const vector<int>& cc: colConditions){
            int u = cc[0], v = cc[1];
            colG[u].insert(v);
        }

        vector<int> row_res = topo_sort(k, rowG);
        if(row_res.size() < k) return {};
        vector<int> col_res = topo_sort(k, colG);
        if(col_res.size() < k) return {};

        vector<int> row(k + 1), col(k + 1);
        for(int i = 0; i < k; i ++){
            row[row_res[i]] = i;
            col[col_res[i]] = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        for(int i = 1; i <= k; i ++)
            res[row[i]][col[i]] = i;

        return res;
    }

private:
    vector<int> topo_sort(int k, vector<set<int>>& g){

        vector<int> indegrees(k + 1, 0);
        for(int u = 1; u <= k; u ++){
            for(int v: g[u]) indegrees[v] ++;
        }

        queue<int> q;
        for(int u = 1; u <= k; u ++)
            if(indegrees[u] == 0) q.push(u);

        vector<int> res;
        while(!q.empty()){
            int u = q.front(); q.pop();
            res.push_back(u);

            for(int v: g[u]){
                indegrees[v] --;
                if(indegrees[v] == 0) q.push(v);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
