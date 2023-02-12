/// Source : https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
/// Author : liuyubobobo
/// Time   : 2023-02-11

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        sort(nums.begin(), nums.end());
        long long res = 0;
        for(int i = 0; i < nums.size(); i ++){
            auto iter1 = lower_bound(nums.begin() + (i + 1), nums.end(), lower - nums[i]);
            auto iter2 = upper_bound(nums.begin() + (i + 1), nums.end(), upper - nums[i]);
            res += iter2 - iter1;
        }
        return res;
    }
};


int main() {

    return 0;
}
