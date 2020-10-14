/// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/description/
/// Author : liuyubobobo
/// Time   : 2020-10-14

#include <iostream>
#include <vector>

using namespace std;

/// Find max value and do Binary Search
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size() == 0) return -1;
        int max_index = max_element(nums.begin(), nums.end()) - nums.begin();

        int l = 0, r = max_index;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }

        l = max_index + 1, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            if(target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
};


int main() {

    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << Solution().search(nums1, target1) << endl;
    // 4

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << Solution().search(nums2, target2) << endl;
    // -1

    vector<int> nums3 = {1, 3};
    int target3 = 3;
    cout << Solution().search(nums3, target3) << endl;
    // 1

    vector<int> nums4 = {5, 1, 3};
    int target4 = 5;
    cout << Solution().search(nums4, target4) << endl;
    // 0

    vector<int> nums5 = {4, 5, 6, 7, 8, 1, 2, 3};
    int target5 = 8;
    cout << Solution().search(nums5, target5) << endl;
    // 4

    return 0;
}