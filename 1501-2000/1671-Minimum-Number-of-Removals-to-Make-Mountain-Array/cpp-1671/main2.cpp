/// Source : https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
/// Author : liuyubobobo
/// Time   : 2020-11-29

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Using LIS O(nlogn) Solution
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp1 = {nums[0]}, len1(n, 1);
        for(int i = 1; i < n; i ++){
            int index = lower_bound(dp1.begin(), dp1.end(), nums[i]) - dp1.begin();
            if(index >= dp1.size()) dp1.push_back(nums[i]);
            else dp1[index] = nums[i];
            len1[i] = index + 1;
        }

        vector<int> dp2 = {nums.back()}, len2(n, 1);
        for(int i = n - 2; i >= 0; i --){
            int index = lower_bound(dp2.begin(), dp2.end(), nums[i]) - dp2.begin();
            if(index >= dp2.size()) dp2.push_back(nums[i]);
            else dp2[index] = nums[i];
            len2[i] = index + 1;
        }

        int res = 3;
        for(int i = 0; i < n; i ++)
            if(len1[i] > 1 && len2[i] > 1)
                res = max(res, len1[i] + len2[i] - 1);
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
