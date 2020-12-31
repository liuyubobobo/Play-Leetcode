/// Source : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
/// Author : liuyubobobo
/// Time   : 2020-11-29

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming - LIS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp1(n, 1);
        for(int i = 1; i < n; i ++){
            for(int j = i - 1; j >= 0; j --)
                if(nums[i] > nums[j]) dp1[i] = max(dp1[i], 1 + dp1[j]);
        }

        vector<int> dp2(n, 1);
        for(int i = n - 2; i >= 0; i --){
            for(int j = i + 1; j < n; j ++)
                if(nums[i] > nums[j]) dp2[i] = max(dp2[i], 1 + dp2[j]);
        }

        int res = 3;
        for(int i = 0; i < n; i ++)
            if(dp1[i] > 1 && dp2[i] > 1)
                res = max(res, dp1[i] + dp2[i] - 1);
        return n - res;
    }
};


int main() {

    vector<int> nums1 = {1, 3, 1};
    cout << Solution().minimumMountainRemovals(nums1) << endl;
    // 0

    vector<int> nums2 = {2,1,1,5,6,2,3,1};
    cout << Solution().minimumMountainRemovals(nums2) << endl;
    // 3

    vector<int> nums3 = {4,3,2,1,1,2,3,1};
    cout << Solution().minimumMountainRemovals(nums3) << endl;
    // 4

    vector<int> nums4 = {1,2,3,4,4,3,2,1};
    cout << Solution().minimumMountainRemovals(nums4) << endl;
    // 1

    return 0;
}
