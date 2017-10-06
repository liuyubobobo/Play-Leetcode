/// Source : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
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
 * Given an array of integers that is already sorted in ascending order,
 * find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2.
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *****************************************************************************************************/


/// Solution 1
/******************************************************
 * Using Binary Search.
 *
 * For every number a = numbers[i],
 * check whether target - a exist in numbers[i+1...length)
 *
 * Time Complexity:  O(nlogn)
 * Space Complexity: O(1)
 *******************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        assert( numbers.size() >= 2 );
        // assert( isSorted(numbers) );

        for( int i = 1 ; i < numbers.size() ; i ++ ){
            int index = binarySearch(numbers, 0, i-1, target-numbers[i] );
            if( index != -1 ){
                const int res[] = {index+1, i+1};
                return vector<int>(res, res + sizeof(res)/sizeof(int));
            }
        }

        throw invalid_argument("the input has no solution");
    }

private:
    // Search target in numbers[left...right]
    // Return the index of the target if it exists;
    // Otherwise, return -1
    int binarySearch( const vector<int>& numbers, int left, int right, int target){

        assert( left >= 0 && left <= right );
        assert( numbers.size() > right );

        int l = left;
        int r = right;
        while( l <= r ){
            int mid = l + (r-l)/2;
            if( target == numbers[mid] )
                return mid;
            else if( target > numbers[mid] )
                l = mid + 1;
            else // target < numbers[mid]
                r = mid - 1;
        }

        return -1;
    }
};

int main() {

    const int nums[] = {2, 7, 11, 15};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 9;

    vector<int> res = Solution().twoSum(nums_vec, target);
    cout<<res[0]<<" , "<<res[1]<<endl;

    return 0;
}