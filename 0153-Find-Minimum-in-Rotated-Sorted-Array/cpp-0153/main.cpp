/// Source : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
/// Author : liuyubobobo
/// Time   : 2018-09-07

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end());
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