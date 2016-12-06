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


/// Solution 2
/***********************************************************************************************
 * Using binary search
 * make another array sum[0...n+1), where sum[i] = the sum of nums[0...i]
 * for every i, we need to search sum[l] where l > i,
 * make sum[l] is the smallest one larger than or equal to sums[i] + s
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 ************************************************************************************************/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        vector<int> sums;
        sums.push_back(0);
        for( int i = 0 ; i < nums.size() ; i ++ )
            sums.push_back( sums[i] + nums[i] );

        int res = nums.size() + 1;
        for( int l = 0 ; l < sums.size() ; l ++ ){
            int index = bsearch( sums , l+1 , sums.size()-1 , sums[l] + s );
            if( index != -1 )
                res = min( res , index - l );
        }

        if( res == nums.size() + 1 )
            return 0;

        return res;
    }

private:
    // in range nums[l...r], find the smallest index i,
    // which makes nums[i] >= t
    int bsearch( const vector<int> &nums, int l, int r, int t){

        int left = l;
        int right = r + 1;
        while( left < right ){
            int mid = left + (right-left)/2;
            if( nums[mid] < t )
                left = mid + 1;
            else // nums[mid] >= t
                right = mid;
        }

        if( right == r + 1 )
            return -1;
        assert( left == right );
        return right;
    }
};

int main() {

    int nums[] = {2, 3, 1, 2, 4, 3};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    int s = 7;

    cout<<Solution().minSubArrayLen( s, nums_vec )<<endl;

    return 0;
}