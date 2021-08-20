/// Source : https://leetcode.com/problems/find-if-path-exists-in-graph/
/// Author : liuyubobobo
/// Time   : 2021-08-20

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Compelxity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        vector<bool> visited(n, false);
        return dfs(g, start, end, visited);
    }

private:
    bool dfs(const vector<vector<int>>& g, int u, int end, vector<bool>& visited){
        visited[u] = true;
        if(u == end) return true;
        for(int v: g[u])
            if(!visited[v] && dfs(g, v, end, visited)) return true;
        return false;
    }
};


int main() {

    return 0;
}
