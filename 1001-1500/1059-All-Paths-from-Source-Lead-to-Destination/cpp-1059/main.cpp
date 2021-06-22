/// Source : https://leetcode.com/problems/all-paths-from-source-lead-to-destination/
/// Author : liuyubobobo
/// Time   : 2021-06-22
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Directed Graph find loop + DFS
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>> g(n);
        vector<int> indeg(n, 0);
        for(const vector<int>& e: edges){
            g[e[0]].push_back(e[1]);
            indeg[e[1]] ++;
        }

        vector<bool> inloop(n, false);
        queue<int> q;
        for(int i = 0; i < n; i ++)
            if(indeg[i] == 0) q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: g[u]){
                indeg[v] --;
                if(indeg[v] == 0)
                    q.push(v);
            }
        }

        for(int i = 0; i < n; i ++)
            if(indeg[i]) inloop[i] = true;

        vector<bool> visited(n, false);
        return dfs(g, source, destination, inloop, visited);
    }

private:
    bool dfs(const vector<vector<int>>& g, int u, int t,
             const vector<bool>& inloop, vector<bool>& visited){

        visited[u] = true;

        if(inloop[u]) return false;
        if(g[u].size() == 0) return u == t;

        for(int v: g[u])
            if(!visited[v] && !dfs(g, v, t, inloop, visited)) return false;
        return true;
    }
};


int main() {

    return 0;
}
