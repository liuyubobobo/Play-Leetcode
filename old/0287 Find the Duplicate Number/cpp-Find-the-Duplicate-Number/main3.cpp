#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <ctime>

using namespace std;


void printArray( const vector<int> &vec){

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

/// Problem
/****************************************************************************************************
 *
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 * prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n^2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 ****************************************************************************************************/


/// Solution 3
/***********************************************************************************************
 * Using the thought of partition in quiksort.
 * When we put m in the proper position according to partition process,
 * there should be m elements before m and n-m-1 elements after m.
 * So if there are more than m elements before m,
 * or more then n-m-1 elements after m,
 * we know which part can we find the duplicate element in.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * But this method changed the original vector
 ************************************************************************************************/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        assert( nums.size() >= 2 );

        srand(time(NULL));

        return __findDuplicate( nums, 0, nums.size()-1);
    }

private:
    int __findDuplicate( vector<int> &nums, int l, int r){

        assert( l <= r );
        if( l == r || nums[l] == nums[r] )
            return nums[l];

        int mid = partition(nums, l, r);

        if( mid + 1 > r || mid - l + 1 > nums[mid] - l )
            return __findDuplicate( nums, l, mid );
        else
            return __findDuplicate( nums, mid+1, r );
    }

    int partition(vector<int>& nums, int l, int r){

        assert( l < r );

        int p = rand()%(r-l+1) + l;
        //assert( l <= p && p <= r );
        swap( nums[l] , nums[p] );

        int i = l + 1; // nums[l+1..<i) <= nums[p]
        int j = r+1;     // nums[j...r] > nums[p]
        while( i < j ){
            if( nums[i] > nums[l] )
                swap(nums[i], nums[--j]);
            else
                i ++;
        }
        swap( nums[l] , nums[i-1] );

        return i-1;
    }
};


int main() {

    const int nums1[] = {1, 1};
    vector<int> nums1_vec( nums1, nums1 + sizeof(nums1)/sizeof(int) );
    cout<<"Solve: ";
    printArray(nums1_vec);
    cout<<Solution().findDuplicate(nums1_vec)<<endl<<endl;


    const int nums2[] = {2, 1, 2};
    vector<int> nums2_vec( nums2, nums2 + sizeof(nums2)/sizeof(int) );
    cout<<"Solve: ";
    printArray(nums2_vec);
    cout<<Solution().findDuplicate(nums2_vec)<<endl<<endl;


    const int nums3[] = {1, 1, 2};
    vector<int> nums3_vec( nums3, nums3 + sizeof(nums3)/sizeof(int) );
    cout<<"Solve: ";
    printArray(nums3_vec);
    cout<<Solution().findDuplicate(nums3_vec)<<endl<<endl;

    return 0;
}