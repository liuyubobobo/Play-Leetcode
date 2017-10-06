/// Source : https://leetcode.com/problems/two-sum/
/// Author : liuyubobobo
/// Time   : 2016-12-02


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/********************************************************************************
 *
 * Given an array of integers,
 * return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 **********************************************************************************/


/// Solution 1
/**************************************
 * Brute Force.
 *
 * Check all the number pairs of nums
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(1)
 **************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        assert( nums.size() >= 2 );

        for( int i = 0 ; i < nums.size() ; i ++ )
            for( int j = i + 1 ; j < nums.size() ; j ++ )
                if( nums[i] + nums[j] == target ){
                    const int res[] = {i,j};
                    return vector<int>(res, res + sizeof(res)/sizeof(int));
                }

        throw invalid_argument("the input has no solution");
    }
};

int main() {

    const int nums[] = {0,4,3,0};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 0;

    vector<int> res = Solution().twoSum(nums_vec, target);
    cout<<res[0]<<" , "<<res[1]<<endl;

    return 0;
}