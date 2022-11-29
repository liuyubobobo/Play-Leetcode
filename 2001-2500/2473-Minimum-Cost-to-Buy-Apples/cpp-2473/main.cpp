/// Source : https://leetcode.com/problems/minimum-cost-to-buy-apples/description/
/// Author : liuyubobobo
/// Time   : 2022-11-28s

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


/// Dij
/// Time Complexity: O(V^2*logE + V^2)
/// Space Complexity: O(V^2)
class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {

        vector<list<pair<int, long long>>> g(n);
        for(const vector<int>& e: roads){
            int u = e[0], v = e[1], w = e[2];
            u --, v --;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<vector<long long>> dis(n);
        for(int u = 0; u < n; u ++) dis[u] = dij(n, g, u);

        vector<long long> res(n, LONG_LONG_MAX);
        for(int s = 0; s < n; s ++){
            for(int t = 0; t < n; t ++)
                if(dis[s][t] != LONG_LONG_MAX / 2)
                    res[s] = min(res[s], dis[s][t] * (k + 1) + appleCost[t]);
        }
        return res;
    }

private:
    vector<long long> dij(int n, const vector<list<pair<int, long long>>>& g, int s){

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, s});
        vector<long long> dis(n, LONG_LONG_MAX / 2);
        dis[s] = 0;
        vector<bool> visited(n, false);
        while(!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(visited[u]) continue;
            visited[u] = true;

            for(const pair<int, long long>& p: g[u]){
                int v = p.first; long long w = p.second;
                if(!visited[v] && d + w < dis[v]){
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis;
    }
};


void print_vec(const vector<long long>& v){
    for(long long e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<vector<int>> roads1 = {
            {1,2,4},{2,3,2},{2,4,5},{3,4,1},{1,3,4}
    };
    vector<int> appleCost1 = {56,42,102,301};
    print_vec(Solution().minCost(4, roads1, appleCost1, 2));

    return 0;
}
