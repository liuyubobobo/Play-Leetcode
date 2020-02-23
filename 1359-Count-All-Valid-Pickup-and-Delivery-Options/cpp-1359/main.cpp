/// Source : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
/// Author : liuyubobobo
/// Time   : 2020-02-23

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n * n)
/// Space Complxity: O(n * n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countOrders(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, n, dp);
    }

private:
    int dfs(int open, int close, int n, vector<vector<int>>& dp){

        if(open == n && close == n) return 1;
        if(dp[open][close] != -1) return dp[open][close];

        int res = 0;
        if(open < n) res += (long long)(n - open) * (long long)dfs(open + 1, close, n, dp) % MOD;
        if(close < open) res += (long long)(open - close) * (long long)dfs(open, close + 1, n, dp) % MOD;
        return dp[open][close] = res % MOD;
    }
};


int main() {

    cout << Solution().countOrders(1) << endl;
    // 1

    cout << Solution().countOrders(2) << endl;
    // 6

    return 0;
}
