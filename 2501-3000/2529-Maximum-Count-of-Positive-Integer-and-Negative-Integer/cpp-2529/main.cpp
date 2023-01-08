/// Source : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/
/// Author : liuyubobobo
/// Time   : 2023-01-08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        auto iter = lower_bound(nums.begin(), nums.end(), 0);
        int neg = iter - nums.begin();

        iter = lower_bound(nums.begin(), nums.end(), 1);
        int pos = nums.end() - iter;

        return max(neg, pos);
    }
};


int main() {

    return 0;
}
