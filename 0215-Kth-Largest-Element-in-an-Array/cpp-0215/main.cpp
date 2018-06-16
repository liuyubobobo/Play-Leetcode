/// Source : https://leetcode.com/problems/kth-largest-element-in-an-array/
/// Author : liuyubobobo
/// Time   : 2017-01-20

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <ctime>

using namespace std;


/// Quick Sort Partition.
/// Time Complexity:  O(n)
/// Space Complexity: O(1)
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

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(nums1, 2) << endl;

    vector<int> nums2 = {3, 1, 2, 4};
    cout << Solution().findKthLargest(nums2, 2) << endl;

    vector<int> nums3 = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    cout << Solution().findKthLargest(nums3, 8) << endl;

    return 0;
}