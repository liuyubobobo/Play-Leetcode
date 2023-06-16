/// Source : https://leetcode.cn/problems/find-the-closest-marked-node/
/// Author : liuyubobobo
/// Time   : 2023-06-16

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(ElogE)
/// Space Complexity: O(V)
class Solution {

private:
    const int INF = INT_MAX / 2;

public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {

        vector<list<pair<int, int>>> g(n);
        for(const vector<int>& edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v, w});
        }

        vector<int> dis(n, INF);
        dis[s] = 0;
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, s});
        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second; pq.pop();
            if(visited[u]) continue;
            visited[u] = true;

            for(const pair<int, int>& p: g[u]){
                int v = p.first, w = p.second;
                if(!visited[v] && dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        int res = INF;
        for(int u: marked) res = min(res, dis[u]);
        return res == INF ? -1 : res;
    }
};


int main() {

    return 0;
}
