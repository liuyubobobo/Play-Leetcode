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


/// Solution 4
/***********************************************************************************************
 * Using Hare and Tortoise Algorithm
 * It's a great algorithm to do the cycle-dectection, credited by Robert Floyed
 *
 * A version of great explanation: http://keithschwarz.com/interesting/code/?dir=find-duplicate
 * wiki: https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * And this method didn't change the original vector
 ************************************************************************************************/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        assert( nums.size() >= 2 );

        int tortoise = 0;
        int hare = 0;

        while( true ){
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if( tortoise == hare )
                break;
        }

        int finder = 0;
        while( true ){
            finder = nums[finder];
            tortoise = nums[tortoise];
            if( tortoise == finder )
                break;
        }

        return finder;
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