/// Source : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
/// Author : liuyubobobo
/// Time   : 2020-02-23

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n * n)
/// Space Complxity: O(n * n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countOrders(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[1][0] = dp[1][1] = n;
        for(int i = 2; i <= n; i ++)
            dp[i][0] = (long long)dp[i - 1][0] * (long long)(n - i + 1) % MOD;

        for(int i = 2; i <= n; i ++)
            for(int j = 1; j <= i; j ++){
                dp[i][j] = 0;
                dp[i][j] += (long long)(n - i + 1) * (long long)dp[i - 1][j] % MOD;
                dp[i][j] += (long long)(i - j + 1) * (long long)dp[i][j - 1] % MOD;
            }
        return dp[n][n];
    }
};


int main() {

    cout << Solution().countOrders(1) << endl;
    // 1

    cout << Solution().countOrders(2) << endl;
    // 6

    return 0;
}
