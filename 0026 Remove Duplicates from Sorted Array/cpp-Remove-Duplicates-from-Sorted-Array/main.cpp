/// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
/// Author : liuyubobobo
/// Time   : 2016-12-06


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*****************************************************************************************************
 *
 * Given a sorted array,
 * remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array,
 * you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2,
 * with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 *******************************************************************************************************/


/// Solution
/**************************************
 * Using two pointer technique
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 **************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if( nums.size() == 0 )
            return 0;

        int res = 1;
        int index = nextDifferentCharacterIndex(nums, 1 );
        int i = 1;
        while( index < nums.size() ){
            res ++;
            nums[i++] = nums[index];
            index = nextDifferentCharacterIndex(nums, index + 1 );
        }

        return res;
    }

private:
    int nextDifferentCharacterIndex( const vector<int> &nums, int p ){
        for( ; p < nums.size() ; p ++ )
            if( nums[p] != nums[p-1] )
                break;
        return p;
    }
};

int main() {

    const int nums[] = {1,1,2};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );

    int newlen = Solution().removeDuplicates( nums_vec );
    cout<<newlen<<endl;
    for( int i = 0 ; i < newlen ; i ++ )
        cout<<nums_vec[i]<<" ";
    cout<<endl;

    return 0;
}