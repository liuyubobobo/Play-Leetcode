/// Source : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(D * target * F)
/// Space Complexity: O(D * target)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int numRollsToTarget(int D, int F, int target) {

        vector<vector<int>> dp(D + 1, vector<int>(target + 1, 0));

        for(int f = 1; f <= min(F, target); f ++)
            dp[1][f] = 1;

        for(int d = 2; d <= D; d ++)
            for(int t = 1; t <= target; t ++)
                for(int f = 1; f <= F && t - f >= 0; f ++)
                    dp[d][t] = (dp[d][t] + dp[d - 1][t - f]) % MOD;
        return dp[D][target];
    }
};


int main() {

    cout << Solution().numRollsToTarget(1, 6, 3) << endl;
    // 1

    cout << Solution().numRollsToTarget(2, 6, 7) << endl;
    // 6

    cout << Solution().numRollsToTarget(2, 5, 10) << endl;
    // 1

    cout << Solution().numRollsToTarget(1, 2, 3) << endl;
    // 0

    cout << Solution().numRollsToTarget(30, 30, 500) << endl;
    // 222616187

    return 0;
}