/// Source : https://leetcode.com/problems/count-ways-to-build-good-strings/
/// Author : liuyubobobo
/// Time   : 2022-11-27

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
    int countGoodStrings(int low, int high, int zero, int one) {

        vector<long long> dp(high + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= high; i ++){
            if(i - zero >= 0) dp[i] += dp[i - zero];
            if(i - one >= 0) dp[i] += dp[i - one];
            dp[i] %= MOD;
        }

        long long res = 0;
        for(int i = low; i <= high; i ++) res += dp[i];
        return res % MOD;
    }
};


int main() {

    return 0;
}
