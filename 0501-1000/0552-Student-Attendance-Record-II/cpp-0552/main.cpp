/// Source : https://leetcode.com/problems/student-attendance-record-ii/
/// Author : liuyubobobo
/// Time   : 2021-08-17

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int checkRecord(int n) {

        if(n == 1) return 3;

        vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
        dp[1][0] = dp[1][1] = 1;
        for(int i = 2; i <= n; i ++){
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
            dp[i][1] = dp[i - 1][0];
            dp[i][2] = dp[i - 1][1];
        }

        long long res = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
        res += (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) * 2ll % MOD;
        res %= MOD;
        for(int i = 1; i + 1 < n; i ++)
            res = (res + (dp[i][0] + dp[i][1] + dp[i][2]) * (dp[n - 1 - i][0] + dp[n - 1 - i][1] + dp[n - 1 - i][2])) % MOD;
        return res;
    }
};

int main() {

    cout << Solution().checkRecord(2) << endl;
    // 8

    cout << Solution().checkRecord(1) << endl;
    // 3

    cout << Solution().checkRecord(10101) << endl;
    // 183236316

    return 0;
}
