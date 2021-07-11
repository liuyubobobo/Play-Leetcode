/// Source : https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
/// Author : liuyubobobo
/// Time   : 2021-07-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Memoization
/// Time Complexity: O(maxTime * (V + E))
/// Space Complexity: O(V * maxTime)
class Solution {

private:
    const int INF = 1e9;

public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {

        int n = passingFees.size();
        vector<map<int, int>> g(n);
        for(const vector<int>& e: edges){
            int a = e[0], b = e[1], w = e[2];
            if(!g[a].count(b) || g[a][b] > w)
                g[a][b] = g[b][a] = w;
        }

        vector<vector<int>> dp(n, vector<int>(maxTime + 1, -1));
        int res = dfs(n, g, passingFees, 0, 0, maxTime, dp);
        return res >= INF ? -1 : res;
    }

private:
    int dfs(int n, const vector<map<int, int>>& g, const vector<int>& fees,
            int u, int t, const int maxTime, vector<vector<int>>& dp){

        if(u == n - 1) return fees[n - 1];
        if(dp[u][t] != -1) return dp[u][t];

        int res = INF;
        for(const pair<int, int>& p: g[u]){
            int v = p.first, w = p.second;
            if(t + w <= maxTime)
                res = min(res, fees[u] + dfs(n, g, fees, v, t + w, maxTime, dp));
        }
        return dp[u][t] = res;
    }
};


int main() {

    return 0;
}
