/// Source : https://leetcode.com/problems/non-decreasing-array/
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
    bool checkPossibility(vector<int>& nums) {

        int i = 0;
        for(i = 1; i < nums.size(); i ++)
            if(nums[i] < nums[i - 1]) break;

        if(i == nums.size()) return true;

        for(int j = i + 1; j < nums.size(); j ++)
            if(nums[j] < nums[j - 1]) return false;

        return i - 1 == 0 ||
               i + 1 == nums.size() ||
               nums[i - 1] <= nums[i + 1] ||
               (i - 2 >= 0 && nums[i - 2] <= nums[i]);
    }
};


int main() {

    vector<int> nums1 = {4, 2, 1};
    cout << Solution().checkPossibility(nums1) << endl;
    // 0

    vector<int> nums2 = {-1, 4, 2, 3};
    cout << Solution().checkPossibility(nums2) << endl;
    // 1

    return 0;
}
