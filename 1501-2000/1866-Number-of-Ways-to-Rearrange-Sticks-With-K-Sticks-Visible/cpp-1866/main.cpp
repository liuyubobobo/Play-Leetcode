/// Source : https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
/// Author : liuyubobobo
/// Time   : 2021-05-18

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(nk)
/// Space Complexity: O(nk)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    long long rearrangeSticks(int n, int k) {

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1ll));
        return dfs(n, k, dp);
    }

private:
    long long dfs(int n, int k, vector<vector<long long>>& dp){

        if(k > n) return 0;
        if(k == 0) return 0;
        if(n == 1) return 1;
        if(dp[n][k] != -1ll) return dp[n][k];
        return dp[n][k] = (dfs(n - 1, k - 1, dp) + (n - 1) * dfs(n - 1, k, dp)) % MOD;
    }
};


int main() {

    cout << Solution().rearrangeSticks(3, 2) << endl;
    // 3

    cout << Solution().rearrangeSticks(5, 5) << endl;
    // 1

    cout << Solution().rearrangeSticks(20, 11) << endl;
    // 647427950

    return 0;
}
