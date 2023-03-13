/// Source : https://leetcode.com/problems/number-of-ways-to-earn-points/description/
/// Author : liuyubobobo
/// Time   : 2023-03-13

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n * target * max_count)
/// Space Complexity: O(n * target)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {

        int n = types.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i ++){
            int count = types[i][0], mark = types[i][1];
            for(int j = 0; j <= count; j ++){
                for(int t = mark * j; t <= target; t ++){
                    dp[i + 1][t] += dp[i][t - mark * j];
                    dp[i + 1][t] %= MOD;
                }
            }
        }
        return dp[n][target];
    }
};


int main() {

    return 0;
}
