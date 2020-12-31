/// Source : https://leetcode.com/problems/majority-element/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/// Sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        assert(nums.size() > 0);

        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main() {

    return 0;
}