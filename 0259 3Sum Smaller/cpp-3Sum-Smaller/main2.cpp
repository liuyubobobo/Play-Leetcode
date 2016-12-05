/// Source : https://leetcode.com/problems/3sum-smaller/
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
 * Given an array of n integers nums and a target,
 * find the number of index triplets i, j, k with 0 <= i < j < k < n
 * that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 *
 * For example, given nums = [-2, 0, 1, 3], and target = 2.
 *
 * Return 2. Because there are two triplets which sums are less than 2:
 *
 * [-2, 0, 1]
 * [-2, 0, 3]
 *****************************************************************************************************/


/// Solution 2
/************************************************************************************************
 * Sort the entire numbers first.
 * For every number nums[i],
 * using two pointers technique to find indexes j and k,
 * which makes nums[i] + nums[j] + nums[k] < target.
 * Then, we can use j and k to calculate how many pairs can be got between nums[j] and nums[k].
 *
 * Time Complexity: O(nlogn) + O(n^2)
 * Space Complexity: O(1)
 ************************************************************************************************/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {

        // There're testcases which the nums.size < 3
        //assert( nums.size() >= 3 );
        if( nums.size() < 3 )
            return 0;

        sort(nums.begin(), nums.end());

        int res = 0;
        for( int i = 0 ; i < nums.size()-2 ; i ++ ){

            int j = i+1, k = nums.size()-1;
            while( j < k ){

                if( nums[i] + nums[j] + nums[k] < target ){
                    res += (k-j);
                    j ++;
                }
                else
                    k --;
            }
        }

        return res;
    }

};

int main() {

    int nums[] = {-2, 0, 1, 3};
    vector<int> nums_vec(nums, nums + sizeof(nums)/sizeof(int));
    int target = 4;

    cout<<Solution().threeSumSmaller(nums_vec, target)<<endl;

    return 0;
}