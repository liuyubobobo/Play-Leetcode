/// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/***********************************************************************************************
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 *
 * Note:
 * - Each element in the result should appear as many times as it shows in both arrays.
 * - The result can be in any order.
 *
 * Follow up:
 * - What if the given array is already sorted?
 *   How would you optimize your algorithm?
 * - What if nums1's size is small compared to nums2's size?
 *   Which algorithm is better?
 * - What if elements of nums2 are stored on disk,
 *   and the memory is limited such that you cannot load all elements into the memory at once?
 ***********************************************************************************************/


/// Solution
/*****************************************************************************
 * Using hash table
 *
 * Time Complexity:  O(n+m)
 * Space Complexity: O(n+m)
 ******************************************************************************/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> hashtable;
        for( int i = 0 ; i < nums1.size() ; i ++ )
            hashtable[nums1[i]] += 1;

        vector<int> res;
        for( int i = 0 ; i < nums2.size() ; i ++ )
            if( hashtable[nums2[i]] > 0 ){
                res.push_back( nums2[i] );
                hashtable[nums2[i]] -= 1;
            }

        return res;
    }
};


int main() {

    const int nums1[] = {1,2,2,1};
    vector<int> nums1_vec( nums1, nums1 + sizeof(nums1)/sizeof(int) );

    const int nums2[] = {2,2};
    vector<int> nums2_vec( nums2, nums2 + sizeof(nums2)/sizeof(int) );

    vector<int> res = Solution().intersect(nums1_vec, nums2_vec);
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}