/// Source : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
/// Author : liuyubobobo
/// Time   : 2021-08-21

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(ElogE)
/// Space Complexity: O(V + E)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> g(n);
        for(const vector<int>& e: roads){
            int a = e[0], b = e[1], w = e[2];
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }

        vector<long long> dis(n, LONG_LONG_MAX / 2);
        vector<int> dp(n, 0);
        vector<bool> visited(n, false);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0ll, 0});
        dp[0] = 1;
        while(!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(visited[u]) continue;
            visited[u] = true;

            for(const pair<int, long long>& p: g[u]){
                int v = p.first;
                long long w = p.second;
                if(!visited[v]){
                    if(d + w < dis[v]){
                        dis[v] = d + w;
                        dp[v] = dp[u];
                        pq.push({dis[v], v});
                    }
                    else if(d + w == dis[v])
                        dp[v] = (dp[v] + dp[u]) % MOD;
                }
            }
        }
//        cout << dis.back() << endl;
        return dp.back();
    }
};


int main() {

    vector<vector<int>> roads = {
            {0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},
            {3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}
    };
    cout << Solution().countPaths(7, roads) << endl;
    // 4

    return 0;
}
