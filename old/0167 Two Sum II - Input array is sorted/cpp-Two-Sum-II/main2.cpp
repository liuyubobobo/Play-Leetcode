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


/// Solution 2
/****************************************************************
 * Using Two Pointer
 *
 * Set two pointer i and j.
 * At the start, i = 0 and j = length - 1
 * If numbers[i] + numbers[j] == target, then we get the answer
 * Otherwise,
 *     if numbers[i] + numbers[j] < target,
 *         we can only increase i to make the sum larger;
 *     else, numbers[i] + numbers[j] > target,
 *         we can only decrease j to make the sum smaller;
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 *****************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        assert( numbers.size() >= 2 );
        // assert( isSorted(numbers) );

        int i = 0 , j = numbers.size() - 1;
        while( i < j ){
            if( numbers[i] + numbers[j] == target ){
                const int res[] = {i+1, j+1};
                return vector<int>(res, res + sizeof(res)/sizeof(int));
            }

            if( numbers[i] + numbers[j] < target )
                i ++;
            else // numbers[i] + numbers[j] > target
                j --;
        }

        throw invalid_argument("the input has no solution");
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