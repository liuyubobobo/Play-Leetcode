/// Source : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
/// Author : liuyubobobo
/// Time   : 2020-10-14

#include <iostream>
#include <vector>

using namespace std;


/// Finding break point and binary search
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {

        if(nums.size() == 0) return false;

        int p = 0;
        for(p = 0; p + 1 < nums.size(); p ++)
            if(nums[p] > nums[p + 1]) break;

        int l = 0, r = p;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return true;
            if(target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }

        l = p + 1, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return true;
            if(target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};


int main() {

    vector<int> nums1 = {4,5,6,7,0,1,2};
    cout << Solution().search(nums1, 0) << endl;

    vector<int> nums2 = {4,5,6,7,8,1,2,3};
    cout << Solution().search(nums2, 8) << endl;

    return 0;
}
