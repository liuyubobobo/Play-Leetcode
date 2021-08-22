/// Source : https://leetcode.com/problems/graph-valid-tree/
/// Author : liuyubobobo
/// Time   : 2021-08-21

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n - 1) return false;

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        vector<bool> visited(n, false);
        int cc = 0;
        for(int i = 0; i < n; i ++)
            if(!visited[i]){
                dfs(g, i, visited);
                cc ++;
            }
        return cc == 1;
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
