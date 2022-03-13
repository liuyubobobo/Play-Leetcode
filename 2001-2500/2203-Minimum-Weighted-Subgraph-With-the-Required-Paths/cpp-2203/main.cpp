/// Source : https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/
/// Author : liuyubobobo
/// Time   : 2022-03-12

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(nlogn)
/// Space Complexity: O(V + E)
class Solution {

private:
    long long INF = LONG_LONG_MAX / 3;

public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {

        vector<vector<pair<int, long long>>> g(n), rg(n);
        for(const vector<int>& e: edges){
            int u = e[0], v = e[1];
            long long w = e[2];
            g[u].push_back({v, w});
            rg[v].push_back({u, w});
        }

        vector<long long> dis1 = dij(n, g, src1);
        if(dis1[dest] >= INF) return -1;

        vector<long long> dis2 = dij(n, g, src2);
        if(dis2[dest] >= INF) return -1;

        vector<long long> rdis = dij(n, rg, dest);

        long long res = rdis[src1] + rdis[src2];
        for(int i = 0; i < n; i ++)
            res = min(res, rdis[i] + dis1[i] + dis2[i]);
        return res;
    }

private:
    vector<long long> dij(int n, const vector<vector<pair<int, long long>>>& g, int s){

        vector<long long> dis(n, INF);
        vector<bool> visited(n, false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, s});
        dis[s] = 0;
        while(!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(visited[u]) continue;
            visited[u] = true;

            for(const pair<int, long long>& p: g[u]){
                int v = p.first;
                long long w = p.second;
                if(!visited[v] && d + w < dis[v]){
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis;
    }
};


int main() {

    vector<vector<int>> edges1 = {
            {0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}
    };
    cout << Solution().minimumWeight(6, edges1, 0, 1, 5) << '\n';
    // 9

    return 0;
}
