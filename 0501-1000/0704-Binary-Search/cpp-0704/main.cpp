/// Source : https://leetcode.com/problems/binary-search/description/
/// Author : liuyubobobo
/// Time   : 2018-06-17

#include <iostream>
#include <vector>

using namespace std;

/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};


int main() {

    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    cout << Solution().search(nums1, target1) << endl;

    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    cout << Solution().search(nums2, target2) << endl;

    return 0;
}