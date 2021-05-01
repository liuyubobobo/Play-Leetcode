/// Source : https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        int res = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i ++)
            if(!visited[i]){
                res ++;
                dfs(g, i, visited);
            }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& g, int u, vector<bool>& visited){

        visited[u] = true;
        for(int v: g[u])
            if(!visited[v]) dfs(g, v, visited);
    }
};


int main() {

    return 0;
}
