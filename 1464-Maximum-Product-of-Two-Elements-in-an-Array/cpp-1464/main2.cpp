/// Source : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-06-05

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};


int main() {

    return 0;
}
