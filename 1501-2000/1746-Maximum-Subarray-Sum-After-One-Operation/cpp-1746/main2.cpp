/// Source : https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/
/// Author : liuyubobobo
/// Time   : 2021-02-05

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0] * nums[0];

        vector<int> dp1(n, nums[0]);
        for(int i = 1; i < n; i ++)
            dp1[i] = max(dp1[i - 1] + nums[i], nums[i]);

        vector<int> dp2(n, nums.back());
        for(int i = n - 2; i >= 0; i --)
            dp2[i] = max(dp2[i + 1] + nums[i], nums[i]);

        int res = max(nums[0] * nums[0] + dp2[1], nums.back() * nums.back() + dp1[n - 2]);
        for(int i = 1; i < n - 1; i ++){
            int tres = nums[i] * nums[i] + max(0, dp1[i - 1]) + max(0, dp2[i + 1]);
            res = max(res, tres);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, -1, -4, -3};
    cout << Solution().maxSumAfterOperation(nums1) << endl;
    // 17

    vector<int> nums2 = {1,-1,1,1,-1,-1,1};
    cout << Solution().maxSumAfterOperation(nums2) << endl;
    // 4

    return 0;
}
