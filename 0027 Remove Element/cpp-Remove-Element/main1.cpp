/// Source : https://leetcode.com/problems/remove-element/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*****************************************************************************************************
 *
 * Given an array and a value,
 * remove all instances of that value in place and return the new length.
 *
 * Do not allocate extra space for another array,
 * you must do this in place with constant memory.
 *
 * The order of elements can be changed.
 * It doesn't matter what you leave beyond the new length.
 *
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 *
 * Your function should return length = 2,
 * with the first two elements of nums being 2.
 *****************************************************************************************************/


/// Solution 1
/**************************************************************************************
 * Two Pointers
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 **************************************************************************************/

class Solution {

public:
    int removeElement(vector<int>& nums, int val) {

        int newl = 0;
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] != val )
                nums[newl++] = nums[i];

        return newl;
    }
};

int main() {

    int nums[] = {3, 2, 2, 3};
    vector<int> nums_vec(nums, nums + sizeof(nums)/sizeof(int));
    int val = 3;

    cout<<Solution().removeElement(nums_vec, val)<<endl;

    return 0;
}