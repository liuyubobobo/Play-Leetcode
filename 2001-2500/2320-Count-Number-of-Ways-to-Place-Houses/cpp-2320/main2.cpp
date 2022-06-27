/// Source : https://leetcode.com/problems/count-number-of-ways-to-place-houses/
/// Author : liuyubobobo
/// Time   : 2022-06-27

#include <iostream>
#include <vector>

using namespace std;


/// DP, just consider one line is enough
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int countHousePlacements(int n) {

        vector<vector<long long>> dp(2, vector<long long>(n, 1));
        for(int i = 1; i < n; i ++){
            dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
            dp[1][i] = dp[0][i - 1];
        }

        long long res = (dp[0][n - 1] + dp[1][n - 1]) % MOD;
        return res * res % MOD;
    }
};


int main() {

    return 0;
}
