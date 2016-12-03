/// Source : https://leetcode.com/problems/3sum/
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
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 *****************************************************************************************************/


/// Solution 2
/***********************************************************************************************
 * Sort the array first.
 * For every different number a, try to find a pair (b, c), which a + b + c  == 0
 *
 * Using this way, we don't need to see whether the triplet is a repeated one
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 *
 * It's a classic problem: https://en.wikipedia.org/wiki/3SUM
 ************************************************************************************************/

class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        int index = 0;
        while( index < nums.size() ){

            // a = nums[index]
            // find the pair (b,c)

            // tricky optimization
            if( nums[index] > 0 )
                break;

            int bindex = index + 1;
            int cindex = nums.size()-1;
            while( bindex < cindex) {

                if (nums[bindex] + nums[cindex] == -nums[index]) {
                    int triplet[] = {nums[index], nums[bindex], nums[cindex]};
                    res.push_back(vector<int>(triplet, triplet + 3));

                    // continue to look for other pairs
                    bindex = next_num_index( nums, bindex );
                    cindex = pre_num_index( nums, cindex);
                }
                else if (nums[bindex] + nums[cindex] < -nums[index])
                    bindex = next_num_index( nums, bindex );
                else //nums[bindex] + nums[cindex] > -nums[index]
                    cindex = pre_num_index( nums, cindex);
            }

            index = next_num_index( nums , index );
        }

        return res;
    }

private:
    int next_num_index( const vector<int> &nums, int cur ){

        for( int i = cur + 1; i < nums.size() ; i ++ )
            if( nums[i] != nums[cur] )
                return i;
        return nums.size();
    }

    int pre_num_index( const vector<int> &nums, int cur){

        for( int i = cur - 1; i >= 0 ; i -- )
            if( nums[i] != nums[cur] )
                return i;
        return -1;
    }
};

int main() {

    int nums[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    vector<vector<int>> res = Solution().threeSum( nums_vec );
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}