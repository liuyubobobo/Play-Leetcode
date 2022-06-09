/// Source : https://leetcode.com/problems/make-array-non-decreasing-or-non-increasing/
/// Author : liuyubobobo
/// Time   : 2022-06-09

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// DP + Basic Optimization
/// Time Complexity: O(n * maxv)
/// Space Complexity: O(n * maxv)
class Solution {

public:
    int convertArray(vector<int>& nums) {

        int n = nums.size(), maxv = *max_element(nums.begin(), nums.end());

        int res1 = solve(n, nums, maxv);

        reverse(nums.begin(), nums.end());
        int res2 = solve(n, nums, maxv);

        return min(res1, res2);
    }

private:
    int solve(int n, const vector<int>& nums, int maxv){

        vector<int> dp(maxv + 1), premin(maxv + 1);
        for(int v = 0; v <= maxv; v ++){
            dp[v] = abs(nums[0] - v);
            if(v) premin[v] = min(premin[v - 1], dp[v]);
            else premin[v] = dp[v];
        }

        for(int i = 1; i < n; i ++){
            vector<int> tdp(maxv + 1);
            for(int v = 0; v <= maxv; v ++)
                tdp[v] = premin[v] + abs(nums[i] - v);

            premin[0] = tdp[0];
            for(int v = 1; v <= maxv; v ++) premin[v] = min(premin[v - 1], tdp[v]);
            dp = tdp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<int> nums1 = {3,2,4,5,0};
    cout << Solution().convertArray(nums1) << '\n';
    // 4

    vector<int> nums2 = {2,2,3,4};
    cout << Solution().convertArray(nums2) << '\n';
    // 0

    vector<int> nums3 = {0};
    cout << Solution().convertArray(nums3) << '\n';
    // 0

    vector<int> nums4 = {0,2,8,0,3};
    cout << Solution().convertArray(nums4) << '\n';
    // 8

    vector<int> nums5 = {4,2,6,7};
    cout << Solution().convertArray(nums5) << '\n';
    // 2

    return 0;
}
