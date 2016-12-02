/// Source : https://leetcode.com/problems/two-sum/
/// Author : liuyubobobo
/// Time   : 2016-12-02


#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

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


/// Solution 3
/*****************************************************************************
 * One-Pass Hash Table
 *
 * We can make the process in one-pass.
 * Every time, we put one number a in the hashtable,
 * and see whether target-a in the current hashtable
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 ******************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        assert( nums.size() >= 2 );

        unordered_map<int,int> table;
        table.insert( pair<int,int>(nums[0], 0) );

        for( int i = 1 ; i < nums.size() ; i ++ ){

            int complement = target - nums[i];
            if( table.find(complement) != table.end() ){
                const int res[] = {i, table[target-nums[i]]};
                return vector<int>(res, res + sizeof(res)/sizeof(int));
            }

            table.insert( pair<int,int>(nums[i], i) );
        }

        throw "the input has no solution";
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