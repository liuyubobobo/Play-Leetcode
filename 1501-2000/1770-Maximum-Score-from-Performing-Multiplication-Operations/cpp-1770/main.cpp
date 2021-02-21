/// Source : https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
/// Author : liuyubobobo
/// Time   : 2021-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(m^2)
/// Space Complexity: O(m^2)
class Solution {

private:
    int n, m;
    const int INF = 1e9;

public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {

        n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m, -INF));
        return dfs(nums, multipliers, 0, 0, dp);
    }

private:
    int dfs(const vector<int>& nums, const vector<int>& mul, int l, int r,
            vector<vector<int>>& dp){

        if(l + r == m) return 0;
        if(dp[l][r] != -INF) return dp[l][r];

        return dp[l][r] = max(nums[l] * mul[l + r] + dfs(nums, mul, l + 1, r, dp),
                              nums[n - 1 - r] * mul[l + r] + dfs(nums, mul, l, r + 1, dp));
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
