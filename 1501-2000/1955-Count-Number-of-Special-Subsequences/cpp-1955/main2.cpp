/// Source : https://leetcode.com/problems/count-number-of-special-subsequences/
/// Author : liuyubobobo
/// Time   : 2021-07-31

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countSpecialSubsequences(vector<int>& nums) {

        int n = nums.size();

        vector<vector<long long>> dp(3, vector<long long>(n, 0ll));
        dp[0][0] = nums[0] == 0;
        for(int i = 1; i < n; i ++){
            dp[0][i] = dp[0][i - 1];
            if(nums[i] == 0)
                dp[0][i] = (1ll + dp[0][i - 1] * 2ll) % MOD;
        }

        for(int v = 1; v <= 2; v ++)
            for(int i = 1; i < n; i ++){
                dp[v][i] = dp[v][i - 1];
                if(nums[i] == v)
                    dp[v][i] = (dp[v - 1][i - 1] + dp[v][i - 1] * 2ll) % MOD;
            }

        return dp[2][n - 1];
    }
};


int main() {

    vector<int> nums1 = {0, 1, 2, 2};
    cout << Solution().countSpecialSubsequences(nums1) << endl;
    // 3

    vector<int> nums2 = {2, 2, 0, 0};
    cout << Solution().countSpecialSubsequences(nums2) << endl;
    // 0

    vector<int> nums3 = {0, 1, 2, 0, 1, 2};
    cout << Solution().countSpecialSubsequences(nums3) << endl;
    // 7

    return 0;
}
