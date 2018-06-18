/// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
/// Author : liuyubobobo
/// Time   : 2018-06-17

#include <iostream>
#include <vector>

using namespace std;

/// Binary Search
/// Make an array of [True, True, ... , True, False, False, ... , False]
/// Find the largest index which is True
///
/// Time Complexity: O(logn)
/// Space Complexity: O(n)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        vector<bool> vec;
        for(int i = 1 ; i < A.size() ; i ++)
            vec.push_back(A[i-1] < A[i]);

        int l = 0, r = vec.size() - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(vec[mid])
                l = mid;
            else
                r = mid - 1;
        }
        return l + 1;
    }
};

int main() {

    vector<int> nums1 = {0, 1, 0};
    cout << Solution().peakIndexInMountainArray(nums1) << endl;

    vector<int> nums2 = {0, 2, 1, 0};
    cout << Solution().peakIndexInMountainArray(nums2) << endl;

    return 0;
}