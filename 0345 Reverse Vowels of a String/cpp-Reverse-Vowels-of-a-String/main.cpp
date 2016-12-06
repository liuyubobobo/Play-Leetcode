/// Source : https://leetcode.com/problems/move-zeroes/
/// Author : liuyubobobo
/// Time   : 2016-12-06


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*******************************************************************
 *
 * Given an array nums,
 * write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12],
 * after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * - You must do this in-place without making a copy of the array.
 * - Minimize the total number of operations.
 ********************************************************************/


/// Solution
/**************************************
 * Using two pointers
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 **************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] ){
                if( i != j )
                    swap( nums[j] , nums[i] );
                j ++;
            }

    }
};

int main() {

    const int nums[] = {0, 1, 0, 3, 12};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );

    Solution().moveZeroes( nums_vec );
    for( int i = 0 ; i < nums_vec.size() ; i ++ )
        cout<<nums_vec[i]<<" ";
    cout<<endl;

    return 0;
}