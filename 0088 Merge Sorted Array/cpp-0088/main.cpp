/// Source : https://leetcode.com/problems/merge-sorted-array/
/// Author : liuyubobobo
/// Time   : 2016-12-06

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Standard merge process in merge sort
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert(nums1.size() == m + n && nums2.size() == n);

        for(int i = n + m - 1 ; i >= n ; i -- )
            nums1[i] = nums1[i - n];

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


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 3, 5, 7};
    int m = nums1.size();

    vector<int> nums2 = {2, 4, 6};
    int n = nums2.size();

    for( int i = 0 ; i < nums2.size() ; i ++ )
        nums1.push_back(0);

    Solution().merge(nums1, m, nums2, n);
    printVec(nums1);

    return 0;
}