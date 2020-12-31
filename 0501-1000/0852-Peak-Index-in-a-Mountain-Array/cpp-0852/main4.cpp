/// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
/// Author : liuyubobobo
/// Time   : 2018-06-17

#include <iostream>
#include <vector>

using namespace std;

/// Binary Search in A directly
/// Time Complexity: O(logn)
/// Space Complexity: O(n)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        int l = 0, r = A.size() - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(A[mid - 1] < A[mid])
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {

    vector<int> nums1 = {0, 1, 0};
    cout << Solution().peakIndexInMountainArray(nums1) << endl;

    vector<int> nums2 = {0, 2, 1, 0};
    cout << Solution().peakIndexInMountainArray(nums2) << endl;

    return 0;
}