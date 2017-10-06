/// Source : https://leetcode.com/problems/3sum-closest/
/// Author : liuyubobobo
/// Time   : 2016-12-03


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*****************************************************************************************************
 *
 * Given an array S of n integers,
 * find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *****************************************************************************************************/


/// Solution
/**************************************************************************************
 * Sort the entire numbers first.
 * For every number a in numbers,
 * use two pointers tecnique to find the pair (b, c),
 * which makes a + b + c is close to target
 *
 * Time Complexity: O(nlogn) + O(n^2)
 * Space Complexity: O(1)
 **************************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        assert( nums.size() >= 3 );

        sort(nums.begin(), nums.end());

        int diff = abs(nums[0]+nums[1]+nums[2]-target);
        int res = nums[0] + nums[1] + nums[2];

        for( int i = 0 ; i < nums.size() ; i ++ ){

            int l = i+1, r = nums.size()-1;
            int t = target - nums[i];
            while( l < r ){
                if( nums[l] + nums[r] == t )
                    return nums[i] + nums[l] + nums[r];
                else{

                    if( abs( nums[l] + nums[r] - t ) < diff ){
                        diff = abs( nums[l] + nums[r] - t );
                        res = nums[i] + nums[l] + nums[r];
                    }

                    if( nums[l] + nums[r] < t )
                        l ++;
                    else   // nums[l] + nums[r] > t
                        r --;
                }

            }
        }

        return res;
    }
};

int main() {

    //int nums[] = {-1, 2, 1, -4};
    int nums[] = {0, 0, 0};
    vector<int> nums_vec(nums, nums + sizeof(nums)/sizeof(int));
    int target = 1;

    cout<<Solution().threeSumClosest(nums_vec, target)<<endl;

    return 0;
}