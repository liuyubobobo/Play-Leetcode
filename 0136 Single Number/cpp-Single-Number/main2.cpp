/// Source : https://leetcode.com/problems/single-number/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/***************************************************************************
 *
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 ***************************************************************************/


/// Solution 2
/**************************************************************************************
 * Using the attribution of xor operation:
 * a ^ 0 = a
 * a ^ a = 0
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 **************************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        assert( nums.size()%2 == 1 );

        int res = 0;
        for( int i = 0 ; i < nums.size() ; i ++ )
            res ^= nums[i];
        return res;
    }
};

int main() {

    int nums[] = {0, 0, 1, 1, 2};
    vector<int> nums_vec(nums, nums + sizeof(nums)/sizeof(int));

    cout<<Solution().singleNumber(nums_vec)<<endl;

    return 0;
}