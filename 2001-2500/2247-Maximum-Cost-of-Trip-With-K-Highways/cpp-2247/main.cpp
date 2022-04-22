/// Source : https://leetcode.com/problems/maximum-cost-of-trip-with-k-highways/
/// Author : liuyubobobo
/// Time   : 2022-04-22

#include <iostream>
#include <vector>

using namespace std;


/// State Compression Memoization
/// Time Complexity: O(2^n * n^2)
/// Space Complexity: O(2^n * n)
class Solution {
public:
    int maximumCost(int n, vector<vector<int>>& highways, int k) {

        vector<vector<pair<int, int>>> g(n);
        for(const vector<int>& e: highways){
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MIN));
        int res = INT_MIN / 2;
        for(int s = 0; s < n; s ++)
            res = max(res, dfs(g, 1 << s, s, k, dp));
        return res < 0 ? -1 : res;
    }

private:
    int dfs(const vector<vector<pair<int, int>>>& g, int state, int u, int k,
            vector<vector<int>>& dp){

        int v_num = __builtin_popcount(state);
        if(v_num == k + 1) return 0;
        if(dp[state][u] != INT_MIN) return dp[state][u];

        int res = INT_MIN / 2;
        for(const pair<int, int>& p: g[u]){
            int v = p.first, w = p.second;
            if((state & (1 << v)) == 0)
                res = max(res, w + dfs(g, state | (1 << v), v, k, dp));
        }
        return dp[state][u] = res;
    }
};


int main() {

    vector<vector<int>> highways1 = {{0,1,4},{2,1,3},{1,4,11},{3,2,3},{3,4,2}};
    cout << Solution().maximumCost(5, highways1, 3) << '\n';
    // 17

    vector<vector<int>> highways2 = {{0,1,3},{2,3,2}};
    cout << Solution().maximumCost(4, highways2, 2) << '\n';
    // -1

    vector<vector<int>> highways3 = {{0,1,0}};
    cout << Solution().maximumCost(2, highways3, 1) << '\n';
    // 0

    return 0;
}
