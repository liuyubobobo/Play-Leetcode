/// Source : https://leetcode.com/problems/kth-largest-element-in-an-array/
/// Author : liuyubobobo
/// Time   : 2017-01-20


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <ctime>

using namespace std;


void printVector( const vector<int>& v){

    for( int i = 0 ; i < v.size() ; i ++)
        cout<<v[i]<<" ";
    cout<<endl;
}

/// Problem
/********************************************************************************
 *
 * Find the kth largest element in an unsorted array.
 * Note that it is the kth largest element in the sorted order,
 * not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 **********************************************************************************/


/// Solution
/**************************************
 * Quick Sort Partition.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 **************************************/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        srand(time(NULL));
        return __findKthLargest(nums, 0, nums.size()-1 , k - 1 );
    }

private:
    int __findKthLargest( vector<int>& nums, int l, int r, int k ){

        if( l == r )
            return nums[l];

        int p = partition( nums, l, r );

        if( p == k )
            return nums[p];
        else if( k < p )
            return __findKthLargest( nums, l, p-1, k);
        else // k > p
            return __findKthLargest( nums, p+1 , r, k );
    }

    int partition( vector<int>& nums, int l, int r ){

        int p = rand()%(r-l+1) + l;
        swap( nums[l] , nums[p] );

        int lt = l + 1; //[l+1...lt) > p ; [lt..i) < p
        for( int i = l + 1 ; i <= r ; i ++ )
            if( nums[i] > nums[l] )
                swap(nums[i], nums[lt++]);

        swap(nums[l], nums[lt-1]);

        return lt-1;
    }
};

int main() {

    int nums1[] = {3, 2, 1, 5, 6, 4};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    cout<<Solution().findKthLargest( vec1, 2 )<<endl;


    int nums2[] = {3, 1, 2, 4};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    cout<<Solution().findKthLargest( vec2, 2 )<<endl;


    int nums3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    vector<int> vec3(nums3, nums3 + sizeof(nums3)/sizeof(int));

    cout<<Solution().findKthLargest( vec3, 8 )<<endl;

    return 0;
}