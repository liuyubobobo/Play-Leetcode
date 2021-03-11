/// Source : https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
/// Author : liuyubobobo
/// Time   : 2021-03-06

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


/// Dijkstra + DAG DP
/// Time Complexity: O(eloge)
/// Space Complexity: O(n + e)
class Solution {

private:
    const int INF = 1e9 + 7;

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        vector<map<int, int>> g(n);
        for(const vector<int>& e: edges){
            int u = e[0] - 1, v = e[1] - 1, w = e[2];
            g[u][v] = w;
            g[v][u] = w;
        }

        vector<int> dis = dij(n, g, n - 1);
//        for(int e: dis) cout << e << " "; cout << endl;

        vector<int> dp(n, -1);
        return dfs(g, 0, dis, dp);
    }

private:
    int dfs(const vector<map<int, int>>& g, int u,
            const vector<int>& dis, vector<int>& dp){

        if(dp[u] != -1) return dp[u];

        int res = 0;
        bool ok = false;
        for(const pair<int, int>& p: g[u]){
            int v = p.first;
            if(dis[u] > dis[v]){
                res = (res + dfs(g, v, dis, dp)) % INF;
                ok = true;
            }
        }

        return dp[u] = (ok ? res : 1);
    }

    vector<int> dij(int n, const vector<map<int, int>>& g, int s){

        vector<bool> visited(n, false);
        vector<int> dis(n, INF);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, n - 1});
        while(!pq.empty()){
            int curd = pq.top().first, cur = pq.top().second;
            pq.pop();

            if(visited[cur]) continue;

            visited[cur] = true;
            dis[cur] = curd;

            for(const pair<int, int>& p: g[cur]){
                int next = p.first, w = p.second;
                if(!visited[next] && curd + w < dis[next]){
                    dis[next] = curd + w;
                    pq.push({dis[next], next});
                }
            }
        }
        return dis;
    }
};


int main() {

    vector<vector<int>> edges1 = {
            {1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}
    };
    cout << Solution().countRestrictedPaths(5, edges1) << endl;
    // 3

    vector<vector<int>> edges2 = {
            {1,3,1},{4,1,2},{7,3,4},{2,5,3},{5,6,1},{6,7,2},{7,5,3},{2,6,4}
    };
    cout << Solution().countRestrictedPaths(7, edges2) << endl;
    // 1

    return 0;
}
