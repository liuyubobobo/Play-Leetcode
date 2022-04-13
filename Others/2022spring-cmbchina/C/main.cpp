/// Source : https://leetcode-cn.com/contest/cmbchina-2022spring/problems/Dk2Ytp/
/// Author : liuyubobobo
/// Time   : 2022-04-13

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
#include <climits>
#include <queue>

using namespace std;


/// BFS
/// Time complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    vector<int> lightSticks(int R, int C, vector<int>& indices) {

        set<int> removed_edges(indices.begin(), indices.end());

        int n = (R + 1) * (C + 1);
        vector<bool> vertex(n, false);
        vector<vector<int>> g(n);

        for(int r = 0; r <= R; r ++){

            for(int edge = 0; edge < C; edge ++){

                int edge_id = r * (C + C + 1) + edge;
                if(removed_edges.count(edge_id)) continue;

                int a = r * (C + 1) + edge, b = a + 1;
                vertex[a] = vertex[b] = true;
                g[a].push_back(b), g[b].push_back(a);
            }

            if(r == R) break;

            for(int edge = 0; edge <= C; edge ++){
                int edge_id = r * (C + C + 1) + C + edge;
                if(removed_edges.count(edge_id)) continue;

                int a = r * (C + 1) + edge, b = (r + 1) * (C + 1) + edge;
                vertex[a] = vertex[b] = true;
                g[a].push_back(b), g[b].push_back(a);
            }
        }

        for(int u = 0; u < n; u ++)
            if(vertex[u]){
                vector<bool> visited(n, false);
                dfs(g, u, visited);

                if(visited != vertex) return {};
                break;
            }

        vector<int> res;
        int best = INT_MAX;
        for(int u = 0; u < n; u ++)
            if(vertex[u]){
                int d = bfs(n, g, u);
                if(d < best) res = {u}, best = d;
                else if(d == best) res.push_back(u);
            }
        return res;
    }

private:
    int bfs(int n, const vector<vector<int>>& g, int s){

        vector<int> dis(n, -1);
        queue<int> q;
        q.push(s);
        dis[s] = 0;
        int res = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int v: g[u])
                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    res = max(res, dis[v]);
                    q.push(v);
                }
        }
        return res;
    }

    void dfs(const vector<vector<int>>& g, int u, vector<bool>& visited){

        visited[u] = true;
        for(int v: g[u])
            if(!visited[v]) dfs(g, v, visited);
    }
};


int main() {

    return 0;
}
