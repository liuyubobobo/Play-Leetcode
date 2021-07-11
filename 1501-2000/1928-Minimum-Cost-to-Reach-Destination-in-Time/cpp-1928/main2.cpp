/// Source : https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
/// Author : liuyubobobo
/// Time   : 2021-07-10

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DP
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

        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INF));
        dp[maxTime][n - 1] = passingFees[n - 1];

        for(int t = maxTime - 1; t >= 0; t --){
            dp[t][n - 1] = passingFees[n - 1];
            for(int u = 0; u < n - 1; u ++)
                for(const pair<int, int>& p: g[u]){
                    int v = p.first, w = p.second;
                    if(t + w <= maxTime)
                        dp[t][u] = min(dp[t][u], passingFees[u] + dp[t + w][v]);
                }
        }
        return dp[0][0] >= INF ? -1 : dp[0][0];
    }
};


int main() {

    return 0;
}
