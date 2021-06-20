/// Source : https://leetcode.com/problems/k-inverse-pairs-array/
/// Author : liuyubobobo
/// Time   : 2021-06-20

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(nk)
/// Space Complexity: O(nk)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int kInversePairs(int n, int k) {

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        dp[1][0] = 1;
        for(int i = 2; i <= n; i ++){

            vector<int> presum(k + 2, 0);
            for(int j = 0; j <= k; j ++)
                presum[j + 1] = (presum[j] + dp[i - 1][j]) % MOD;

            dp[i][0] = 1;
            for(int j = 1; j <= k; j ++)
                dp[i][j] = (presum[j + 1] - presum[max(0, j - (i - 1))] + MOD) % MOD;
        }
        return dp[n][k];
    }
};


int main() {

    return 0;
}
