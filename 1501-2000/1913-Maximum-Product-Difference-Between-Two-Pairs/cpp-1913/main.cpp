/// Source : https://leetcode.com/problems/maximum-product-difference-between-two-pairs/submissions/
/// Author : liuyubobobo
/// Time   : 2021-06-26

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};


int main() {

    return 0;
}
