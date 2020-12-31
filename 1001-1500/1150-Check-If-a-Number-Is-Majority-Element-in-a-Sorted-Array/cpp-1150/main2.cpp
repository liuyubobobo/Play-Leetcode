/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        vector<int>::iterator iter1 = lower_bound(nums.begin(), nums.end(), target);
        vector<int>::iterator iter2 = upper_bound(nums.begin(), nums.end(), target);
        return iter2 - iter1 > nums.size() / 2;
    }
};


int main() {
    return 0;
}