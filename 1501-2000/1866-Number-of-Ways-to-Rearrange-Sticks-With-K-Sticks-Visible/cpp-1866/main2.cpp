/// Source : https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
/// Author : liuyubobobo
/// Time   : 2021-05-18

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(nk)
/// Space Complexity: O(nk)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    long long rearrangeSticks(int n, int k) {

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0ll));
        dp[1][1] = 1ll;
        for(int i = 2; i <= n; i ++){
            for(int j = 1; j <= min(i, k); j ++)
                dp[i][j] = (dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j]) % MOD;
        }

        return dp[n][k];
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
