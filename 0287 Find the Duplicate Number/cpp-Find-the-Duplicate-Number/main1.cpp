#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/****************************************************************************************************
 *
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 ****************************************************************************************************/


/// Solution 1
/***********************************************************************************************
 * Sort and scan.
 *
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 ************************************************************************************************/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        assert( nums.size() >= 2 );

        sort(nums.begin(), nums.end());
        for( int i = 1 ; i < nums.size() ; i ++ )
            if( nums[i] == nums[i-1] )
                return nums[i];

        throw invalid_argument("the input has no solution");
    }
};

int main() {

    const int nums[] = {1, 1};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );

    cout<<Solution().findDuplicate(nums_vec)<<endl;
    return 0;
}