/// Source : https://leetcode.com/problems/merge-sorted-array/
/// Author : liuyubobobo
/// Time   : 2016-12-06


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/***************************************************************************************
 *
 * Given two sorted integer arrays nums1 and nums2,
 * merge nums2 into nums1 as one sorted array.
 *
 * Note:
 * - You may assume that nums1 has enough space
 *   (size that is greater or equal to m + n) to hold additional elements from nums2.
 *   The number of elements initialized in nums1 and nums2 are m and n respectively.
 **************************************************************************************/


/// Solution
/**************************************************************************************
 * Standard merge process in merge sort
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 **************************************************************************************/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert( nums1.size() == m+n && nums2.size() == n );

        for( int i = n+m-1 ; i >= n ; i -- )
            nums1[i] = nums1[i-n];

        int i = n;  // pointer for nums1 [n, n+m)
        int j = 0;  // pointer for nums2 [0, n)
        int k = 0;  // pointer merged nums1 [0, n+m)
        while( k < n + m ){
            if( i >= n+m )
                nums1[k++] = nums2[j++];
            else if( j >= n )
                nums1[k++] = nums1[i++];
            else if( nums1[i] < nums2[j] )
                nums1[k++] = nums1[i++];
            else
                nums1[k++] = nums2[j++];
        }
    }
};

int main() {

    int nums1[] = {1, 3, 5, 7};
    int nums2[] = {2, 4, 6};

    vector<int> nums1_vec(nums1, nums1 + sizeof(nums1)/sizeof(int));
    int m = nums1_vec.size();

    vector<int> nums2_vec(nums2, nums2 + sizeof(nums2)/sizeof(int));
    int n = nums2_vec.size();

    for( int i = 0 ; i < nums2_vec.size() ; i ++ )
        nums1_vec.push_back(0);

    Solution().merge(nums1_vec, m, nums2_vec, n);
    for( int i = 0 ; i < nums1_vec.size() ; i ++ )
        cout<<nums1_vec[i]<<" ";
    cout<<endl;

    return 0;
}