/// Source : https://leetcode.com/problems/remove-element/
/// Author : liuyubobobo
/// Time   : 2016-12-05

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;

/// Two Pointers
/// Move the deleted element to the last
/// This method would be save the unnecessary copy when the removed element is rare.
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int removeElement(vector<int>& nums, int val) {

        int newl = nums.size();
        int i = 0;
        while( i < newl )
            if( nums[i] == val )
                nums[i] = nums[--newl];
            else
                i ++;

        return newl;
    }
};


int main() {

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    cout << Solution().removeElement(nums, val) << endl;

    return 0;
}