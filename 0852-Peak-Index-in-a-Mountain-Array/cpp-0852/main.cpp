/// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
/// Author : liuyubobobo
/// Time   : 2018-06-17

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Two Linear Scans
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        int maxValue = A[0];
        for(int a: A)
            maxValue = max(maxValue, a);

        for(int i = 0 ; i < A.size() ; i ++)
            if(A[i] == maxValue)
                return i;

        assert(false);
        return -1;
    }
};

int main() {

    vector<int> nums1 = {0, 1, 0};
    cout << Solution().peakIndexInMountainArray(nums1) << endl;

    vector<int> nums2 = {0, 2, 1, 0};
    cout << Solution().peakIndexInMountainArray(nums2) << endl;

    return 0;
}