/// Source : https://leetcode.com/problems/count-number-of-ways-to-place-houses/
/// Author : liuyubobobo
/// Time   : 2022-06-25

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
    int countHousePlacements(int n) {

        vector<vector<long long>> dp(4, vector<long long>(n, 0));
        dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 1;
        for(int i = 1; i < n; i ++){
            for(int cur_state = 0; cur_state < 4; cur_state ++){
                int cur1 = cur_state / 2, cur2 = cur_state % 2;
                for(int pre_state = 0; pre_state < 4; pre_state ++){
                    int pre1 = pre_state / 2, pre2 = pre_state % 2;
                    if((cur1 && pre1) || (cur2 && pre2)) continue;
                    dp[cur_state][i] += dp[pre_state][i - 1];
                }
                dp[cur_state][i] %= MOD;
            }
        }

        long long res = 0;
        for(int state = 0; state < 4; state ++) res += dp[state][n - 1];
        return res % MOD;
    }
};

int main() {

    return 0;
}
