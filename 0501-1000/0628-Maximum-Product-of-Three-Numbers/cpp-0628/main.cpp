/// Source : https://leetcode.com/problems/maximum-product-of-three-numbers/
/// Author : liuyubobobo
/// Time   : 2021-01-19

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int res = INT_MIN;
        res = max(res, nums[0] * nums[1] * nums[2]);
        res = max(res, nums.back() * nums[nums.size() - 2] * nums[nums.size() - 3]);
        res = max(res, nums[0] * nums[1] * nums.back());
        return res;
    }
};


int main() {

    return 0;
}
