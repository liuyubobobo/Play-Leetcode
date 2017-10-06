#include <iostream>
#include <vector>

using namespace std;

/// Problem
/***************************************************************************************
 * Given a non-empty array containing only positive integers,
 * find if the array can be partitioned into two subsets such that
 * the sum of elements in both subsets is equal.
 *
 * Note:
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 *
 * Example 1:
 * Input: [1, 5, 11, 5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 * Example 2:
 * Input: [1, 2, 3, 5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 ***************************************************************************************/


/// Solution
/**************************************************************************************
 * 0-1 backsack problem
 *
 * Time Complexity: O(array_size^2 * max_elelemt_value)
 * Space Complexity: O(array_size * max_elelemt_value)
 **************************************************************************************/

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        if( nums.size() == 0 )
            return false;

        int sum = 0;
        for( int i = 0 ; i < nums.size() ; i ++ )
            sum += nums[i];

        if( sum % 2 == 1 )
            return false;

        vector<bool> dp( sum/2+1 , false );
        dp[0] = true;
        for( int i = 0 ; i < nums.size() ; i ++ ){

            for( int j = sum/2 ; j >= nums[i] ; j -- )
                dp[j] = dp[j] || dp[j-nums[i]];
        }

        return dp[sum/2];
    }
};

int main() {

    int nums1[] = {1, 5, 11, 5};
    vector<int> vec1( nums1, nums1 + sizeof(nums1)/sizeof(int));
    if( Solution().canPartition(vec1) )
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}