/// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
/// Author : liuyubobobo
/// Time   : 2018-06-16

#include <iostream>
#include <vector>

using namespace std;

/// One Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        for(int i = 1 ; i < A.size() ; i ++)
            if(A[i - 1] > A[i])
                return i - 1;
        return A.size() - 1;
    }
};

int main() {

    vector<int> nums1 = {0, 1, 0};
    cout << Solution().peakIndexInMountainArray(nums1) << endl;

    vector<int> nums2 = {0, 2, 1, 0};
    cout << Solution().peakIndexInMountainArray(nums2) << endl;

    return 0;
}