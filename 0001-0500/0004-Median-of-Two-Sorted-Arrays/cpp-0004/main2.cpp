/// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
/// Author : liuyubobobo
/// Time   : 2021-03-02

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Binary Search
/// Time Complexity: O(log(min(n, m)))
/// Space Complexity: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int len = nums1.size() + nums2.size();

        int a = select(nums1, 0, (int)nums1.size() - 1,
                       nums2, 0, (int)nums2.size() - 1, len / 2);
        if(len % 2) return a;

        int b = select(nums1, 0, (int)nums1.size() - 1,
                       nums2, 0, (int)nums2.size() - 1, len / 2 - 1);
        return (a + b) / 2.0;
    }

private:
    int select(const vector<int>& nums1, int l1, int r1,
               const vector<int>& nums2, int l2, int r2, int k){

        if(l1 > r1) return nums2[l2 + k];
        if(l2 > r2) return nums1[l1 + k];

        int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
        int mid1 = len1 / 2, mid2 = len2 / 2;
        int e1 = nums1[l1 + mid1], e2 = nums2[l2 + mid2];
        if(mid1 + mid2 < k){
            if(e1 > e2)
                return select(nums1, l1, r1, nums2, l2 + mid2 + 1, r2, k - mid2 - 1);
            else
                return select(nums1, l1 + mid1 + 1, r1, nums2, l2, r2, k - mid1 - 1);
        }
        else{
            if(e1 > e2)
                return select(nums1, l1, l1 + mid1 - 1, nums2, l2, r2, k);
            else
                return select(nums1, l1, r1, nums2, l2, l2 + mid2 - 1, k);
        }
    }
};


int main() {

    vector<int> nums11 = {1, 3};
    vector<int> nums12 = {2};
    cout << Solution().findMedianSortedArrays(nums11, nums12) << endl;
    // 2

    vector<int> nums21 = {1, 2};
    vector<int> nums22 = {3, 4};
    cout << Solution().findMedianSortedArrays(nums21, nums22) << endl;
    // 2.5

    vector<int> nums31 = {};
    vector<int> nums32 = {1};
    cout << Solution().findMedianSortedArrays(nums31, nums32) << endl;
    // 1

    vector<int> nums41 = {1, 2, 2};
    vector<int> nums42 = {1, 2, 3};
    cout << Solution().findMedianSortedArrays(nums41, nums42) << endl;
    // 2

    return 0;
}