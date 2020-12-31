/// Source : https://leetcode.com/problems/kth-largest-element-in-an-array/
/// Author : liuyubobobo
/// Time   : 2018-01-07

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <ctime>

using namespace std;


/// Sorting
/// Time Complexity:  O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end(), [](int a, int b){return a > b;});
        return nums[k - 1];
    }
};


int main() {

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(nums1, 2) << endl;
    // 5

    vector<int> nums2 = {3, 1, 2, 4};
    cout << Solution().findKthLargest(nums2, 2) << endl;
    // 3

    vector<int> nums3 = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    cout << Solution().findKthLargest(nums3, 8) << endl;
    // 3

    return 0;
}