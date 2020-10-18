/// Source : https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(nk)
/// Space Complexity: O(n)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int numberOfSets(int n, int k) {

        vector<int> dp(n, 1);
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = (presum[i] + dp[i]) % MOD;

        for(int i = 0; i < k; i ++){
            dp[n - 1] = 0;
            for(int start = n - 2; start >= 0; start --)
                dp[start] = ((dp[start + 1] + presum[n]) % MOD - presum[start + 1] + MOD) % MOD;

            presum[0] = 0;
            for(int i = 0; i < n; i ++)
                presum[i + 1] = (presum[i] + dp[i]) % MOD;
        }
        return dp[0];
    }
};


int main() {

    cout << Solution().numberOfSets(4, 2) << endl;
    // 5

    cout << Solution().numberOfSets(3, 1) << endl;
    // 3

    cout << Solution().numberOfSets(30, 7) << endl;
    // 796297179

    cout << Solution().numberOfSets(31, 26) << endl;
    // 367290

    return 0;
}
