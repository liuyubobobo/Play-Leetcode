/// Source : https://leetcode.com/problems/number-of-good-binary-strings/
/// Author : liuyubobobo
/// Time   : 2023-01-14

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(maxLength)
/// Space Complexity: O(maxLength)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {

        vector<long long> dp(maxLength + 1, -1);
        long long res = 0;
        for(int len = minLength; len <= maxLength; len ++)
            res += solve(len, oneGroup, zeroGroup, dp), res %= MOD;
        return res;
    }

private:
    long long solve(int len, int one, int zero, vector<long long>& dp){

        if(len < 0) return 0;
        if(len == 0) return 1;
        if(dp[len] != -1) return dp[len];

        long long res = solve(len - one, one, zero, dp);
        res += solve(len - zero, one, zero, dp);
        return dp[len] = res % MOD;
    }
};


int main() {

    cout << Solution().goodBinaryStrings(2, 3, 1, 2) << '\n';
    // 5

    return 0;
}
