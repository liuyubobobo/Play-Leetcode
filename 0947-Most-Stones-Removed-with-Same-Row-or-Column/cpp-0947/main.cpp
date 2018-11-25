/// Source : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
/// Author : liuyubobobo
/// Time   : 2018-11-25

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Using DFS to calculate connected components
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        vector<unordered_set<int>> g(n);
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    g[i].insert(j);
                    g[j].insert(i);
                }

        int res = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i ++)
            if(!visited[i])
                res += dfs(g, i, visited) - 1;

        return res;
    }

private:
    int dfs(const vector<unordered_set<int>> &g, int v, vector<bool> &visited){

        visited[v] = true;
        int res = 1;
        for(int next: g[v])
            if(!visited[next])
                res += dfs(g, next, visited);
        return res;
    }
};


int main() {

    vector<vector<int>> stones1 = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << Solution().removeStones(stones1) << endl;
    // 5

    vector<vector<int>> stones2 = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    cout << Solution().removeStones(stones2) << endl;
    // 3

    vector<vector<int>> stones3 = {{0,0}};
    cout << Solution().removeStones(stones3) << endl;
    // 0

    return 0;
}