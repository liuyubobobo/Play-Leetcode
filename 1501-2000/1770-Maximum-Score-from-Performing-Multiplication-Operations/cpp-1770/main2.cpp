/// Source : https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
/// Author : liuyubobobo
/// Time   : 2021-02-21

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m^2)
/// Space Complexity: O(m^2)
class Solution {

public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {

        int n = nums.size(), m = mul.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for(int l = 1; l <= m; l ++)
            dp[l][0] = dp[l - 1][0] + mul[l - 1] * nums[l - 1];
        for(int r = 1; r <= m; r ++)
            dp[0][r] = dp[0][r - 1] + mul[r - 1] * nums[n - r];

        for(int l = 1; l < m; l ++)
            for(int r = 1; l + r <= m; r ++)
                dp[l][r] = max(dp[l - 1][r] + mul[l + r - 1] * nums[l - 1],
                               dp[l][r - 1] + mul[l + r - 1] * nums[n - r]);

        int res = INT_MIN;
        for(int i = 0; i <= m; i ++) res = max(res, dp[i][m - i]);
        return res;
    }
};


int main() {

    vector<int> nums1 = {1,2 , 3}, mul1 = {3, 2, 1};
    cout << Solution().maximumScore(nums1, mul1) << endl;
    // 14

    vector<int> nums2 = {-5,-3,-3,-2,7,1}, mul2 = {-10,-5,3,4,6};
    cout << Solution().maximumScore(nums2, mul2) << endl;
    // 102

    return 0;
}
