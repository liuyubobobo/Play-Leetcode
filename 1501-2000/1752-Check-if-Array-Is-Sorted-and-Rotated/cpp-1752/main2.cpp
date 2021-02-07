/// Source : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {

        int i;
        for(i = 1; i < nums.size(); i ++)
            if(nums[i - 1] > nums[i])
                break;

        if(i == nums.size()) return true;

        for(int j = i + 1; j < nums.size(); j ++)
            if(nums[j] < nums[j - 1]) return false;
        return nums[0] >= nums.back();
    }
};


int main() {

    vector<int> nums1 = {2, 1, 3, 4};
    cout << Solution().check(nums1) << endl;
    // 0

    vector<int> nums2 = {3, 4, 5, 1, 2};
    cout << Solution().check(nums2) << endl;
    // 1

    return 0;
}
