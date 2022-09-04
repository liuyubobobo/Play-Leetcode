/// Source : https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(k^2)
/// Space Complexity: O(k^2)
class Solution {

private:
    const long long MOD = 1e9 + 7;
    int OFFSET = 1000;

public:
    int numberOfWays(int startPos, int endPos, int k) {

        OFFSET = -(startPos - k);
        vector<vector<long long>> dp(startPos + k + OFFSET, vector<long long>(k + 1, -1));
        return dfs(startPos, k, endPos, dp);
    }

    long long dfs(int pos, int k, int target, vector<vector<long long>>& dp){

        if(k == 0) return pos == target;
        if(dp[pos + OFFSET][k] != -1) return dp[pos + OFFSET][k];

        long long res = 0;
        res += dfs(pos + 1, k - 1, target, dp);
        res += dfs(pos - 1, k - 1, target, dp);
        return dp[pos + OFFSET][k] = res % MOD;
    }
};


int main() {

    cout << Solution().numberOfWays(1, 2, 3) << '\n';
    // 3

    cout << Solution().numberOfWays(2, 5, 10) << '\n';
    // 0

    cout << Solution().numberOfWays(921, 413, 716) << '\n';
    // 0

    return 0;
}
