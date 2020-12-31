/// Source : https://leetcode.com/problems/subarray-product-less-than-k/description/
/// Author : liuyubobobo
/// Time   : 2017-10-32

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/// log the numbers and binary search
///
/// Time Complexity: O(n*logn), n = len(nums)
/// Space Complexity: O(n)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        vector<double> logsums;
        logsums.push_back(0.0);
        for(int num: nums)
            logsums.push_back(log((double)num));
        double logk = log((double)k);

        for(int i = 1 ; i <= logsums.size() ; i ++)
            logsums[i] += logsums[i-1];

        int res = 0;
        for(int i = 1 ; i < logsums.size() ; i ++){
            vector<double>::iterator iter =
                    lower_bound(logsums.begin() + i, logsums.end(),
                                logsums[i-1] + logk);
            res += (iter - logsums.begin()) - i;
        }

        return res;
    }
};

int main() {

    int nums1[] = {10, 5, 2, 6};
    int k1 = 100;
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().numSubarrayProductLessThanK(vec1, k1) << endl;

    int nums2[] = {1, 2, 3};
    int k2 = 0;
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().numSubarrayProductLessThanK(vec2, k2) << endl;

    return 0;
}