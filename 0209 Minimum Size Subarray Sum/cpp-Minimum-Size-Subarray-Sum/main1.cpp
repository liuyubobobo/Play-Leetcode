/// Source : https://leetcode.com/problems/minimum-size-subarray-sum/
/// Author : liuyubobobo
/// Time   : 2016-12-06


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/***********************************************************************************
 *
 * Given an array of n positive integers and a positive integer s,
 * find the minimal length of a subarray of which the sum ≥ s.
 * If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 *
 * click to show more practice.
 *
 * More practice:
 * If you have figured out the O(n) solution,
 * try coding another solution of which the time complexity is O(n log n).
 *
 * Credits:
 ( Special thanks to @Freezen for adding this problem and creating all test cases.
 **************************************************************************************/


/// Solution 1
/***********************************************************************************************
 * Using two pointer technique
 * the solution should be like nums[l...r)
 * then, we search for every l
 * but we don't need to recalculate every sum of l,l+1,l+2..<r,
 * we can reuse the result of l-1,l+1...<r
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 ************************************************************************************************/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int res = nums.size() + 1;
        int cur = 0;
        int r = 0;
        for( int l = 0 ; l < nums.size() ; l ++ ){

            if( l > 0 )
                cur -= nums[l-1];

            while( r < nums.size() && cur < s )
                cur += nums[r++];

            if( cur < s )
                break;

            res = min(res,r-l);
        }

        if( res == nums.size() + 1 )
            return 0;

        return res;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    int s = 7;

    cout<<Solution().minSubArrayLen( s, nums_vec )<<endl;

    return 0;
}