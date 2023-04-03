/// Source : https://leetcode.com/problems/shortest-cycle-in-a-graph/description/
/// Author : liuyubobobo
/// Time   : 2023-04-02

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {

        vector<list<int>> g(n);
        for(const vector<int>& e : edges){
            int u = e[0], v = e[1];
            g[u].push_back(v), g[v].push_back(u);
        }

        int res = INT_MAX;
        for(const vector<int>& e: edges){
            int u = e[0], v = e[1];
            g[u].remove(v), g[v].remove(u);

            vector<int> dis = bfs(n, g, u);
            if(dis[v] != INT_MAX) res = min(res, dis[v] + 1);

            g[u].push_back(v), g[v].push_back(u);
        }
        return res == INT_MAX ? -1 : res;
    }

private:
    vector<int> bfs(int n, const vector<list<int>>& g, int s){

        vector<int> dis(n, INT_MAX);
        queue<int> q;
        q.push(s), dis[s] = 0;

        while(!q.empty()){
            int u = q.front(), d = dis[u]; q.pop();
            for(int v: g[u]){
                if(dis[v] != INT_MAX) continue;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
        return dis;
    }
};


int main() {

    vector<vector<int>> edges1 = {{2,1},{0,1},{4,1},{3,0},{1,3}};
    cout << Solution().findShortestCycle(5, edges1) << '\n';
    // 3

    return 0;
}
