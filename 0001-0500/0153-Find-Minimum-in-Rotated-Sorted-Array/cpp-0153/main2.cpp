/// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
/// Author : liuyubobobo
/// Time   : 2018-09-07

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {

        assert(nums.size() > 0);
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return min(nums[0], nums[1]);

        int l = 0, r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[l] <= nums[mid] && nums[mid] <= nums[r])
                return nums[l];

            if(nums[l] > nums[mid])
                l = l + 1, r = mid;
            else if(nums[r] < nums[mid])
                l = mid + 1;
            else
                assert(false);
        }
        return nums[l];
    }
};


int main() {

    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << Solution().findMin(nums1) << endl; // 1

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << Solution().findMin(nums2) << endl; // 0

    vector<int> nums3 = {3, 1, 2};
    cout << Solution().findMin(nums3) << endl; // 1

    vector<int> nums4 = {7, 1, 2, 3, 4, 5, 6};
    cout << Solution().findMin(nums4) << endl; // 1

    return 0;
}