/// Source : https://leetcode.com/problems/4sum/
/// Author : liuyubobobo
/// Time   : 2016-12-06


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*****************************************************************************
 *
 * Given an array S of n integers,
 * are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note: The solution set must not contain duplicate quadruplets.
 *
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 *  [-1,  0, 0, 1],
 *  [-2, -1, 1, 2],
 *  [-2,  0, 0, 2]
 * ]
 *******************************************************************************/


/// Solution
/***********************************************************************************************
 * Using two pointer technique
 *
 * Sort the array first.
 * For every different number a and b, try to find a pair (c, d), which a + b + c + d == 0
 *
 * Using this way, we don't need to see whether the triplet is a repeated one
 *
 * Time Complexity: O(nlogn) + O(n^3)
 * Space Complexity: O(1)
 ************************************************************************************************/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        if( nums.size() < 4 )
            return res;

        sort( nums.begin() , nums.end() );

        for( int i = 0 ; i <= nums.size() - 4 ; i = nextNumberIndex(nums,i) )
            for( int j = i+1 ; j <= nums.size() - 3 ; j = nextNumberIndex(nums,j)){

                //cout<<"check for "<<nums[i]<<" "<<nums[j];

                int t = target - nums[i] - nums[j];
                int p1 = j+1;
                int p2 = nums.size()-1;
                //cout<<" "<<nums[p1]<<" "<<nums[p2]<<endl;
                if( p1 >= p2 )
                    break;

                while( p1 < p2 ){
                    if( nums[p1] + nums[p2] == t ){
                        int one_res[] = { nums[i] , nums[j] , nums[p1] , nums[p2] };
                        vector<int> one_res_vec(one_res, one_res+4);
                        res.push_back( one_res_vec );

                        p1 = nextNumberIndex(nums, p1);
                        p2 = preNumberIndex(nums, p2);
                    }
                    else if( nums[p1] + nums[p2] < t )
                        p1 = nextNumberIndex( nums , p1 );
                    else // nums[p1] + nums[p2] > t
                        p2 = preNumberIndex( nums , p2 );

                }
            }

        return res;
    }

private:
    int nextNumberIndex( const vector<int> &nums , int index ){

        for( int i = index + 1 ; i < nums.size() ; i ++ )
            if( nums[i] != nums[index] )
                return i;
        return nums.size();
    }

    int preNumberIndex( const vector<int> &nums , int index ){

        for( int i = index-1 ; i >= 0 ; i -- )
            if( nums[i] != nums[index] )
                return i;
        return -1;
    }
};

int main() {

    int nums[] = {1, 0, -1, 0, -2, 2};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));
    int target = 0;

    vector<vector<int>> res = Solution().fourSum( nums_vec , target );
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}