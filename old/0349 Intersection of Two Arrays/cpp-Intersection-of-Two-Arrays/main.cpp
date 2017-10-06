/// Source : https://leetcode.com/problems/intersection-of-two-arrays/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/********************************************************************************
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 **********************************************************************************/


/// Solution
/*****************************************************************************
 * Using hashtable
 *
 * Time Complexity:  O(m+n)
 * Space Complexity: O(m+n)
 ******************************************************************************/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> hashtable;
        for( int i = 0 ; i < nums1.size() ; i ++ )
            hashtable.insert(nums1[i]);

        unordered_set<int> res_set;
        for( int i = 0 ; i < nums2.size() ; i ++ )
            if( hashtable.find( nums2[i] ) != hashtable.end() )
                res_set.insert( nums2[i] );

        vector<int> res;
        for(unordered_set<int>::iterator iter = res_set.begin() ; iter != res_set.end() ; iter ++ )
            res.push_back( *iter );

        return res;
    }
};


int main() {

    const int nums1[] = {1,2,2,1};
    vector<int> nums1_vec( nums1, nums1 + sizeof(nums1)/sizeof(int) );

    const int nums2[] = {2,2};
    vector<int> nums2_vec( nums2, nums2 + sizeof(nums2)/sizeof(int) );

    vector<int> res = Solution().intersection(nums1_vec, nums2_vec);
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}