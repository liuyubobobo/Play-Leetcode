/// Source : https://leetcode.com/problems/subarray-product-less-than-k/description/
/// Author : liuyubobobo
/// Time   : 2017-10-32

#include <iostream>
#include <vector>

using namespace std;

/// Sliding Window
/// Time Complexity: O(len(nums))
/// Space Complexity: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int res = 0;

        int l = 0, r = 0; // sliding windos nums[l, r)
        int prod = 1;
        while(l < nums.size()){

            if(r < nums.size() && prod * nums[r] < k){
                prod *= nums[r];
                r ++;
            }
           else{ // r >= nums.size() || prod * nums[r] >= k
                res += (r-l);
                prod /= nums[l];
                l ++;
                if(l > r)
                    r = l;
            }
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