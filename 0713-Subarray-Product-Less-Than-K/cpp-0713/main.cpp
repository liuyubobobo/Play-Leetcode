/// Source : https://leetcode.com/problems/subarray-product-less-than-k/description/
/// Author : liuyubobobo
/// Time   : 2017-10-32
/// Updated: 2018-03-24

#include <iostream>
#include <vector>

using namespace std;

/// Sliding Window
/// Time Complexity: O(len(nums))
/// Space Complexity: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 0)
            return 0;

        int res = 0;

        int l = 0, r = 0; // sliding windos nums[l, r)
        int prod = 1;
        while(l < nums.size()){

            if(r < nums.size() && prod * nums[r] < k){
                prod *= nums[r];
                r ++;
            }
            else if(l == r){ // nums[l] >= k
                l ++;
                r ++;
            }
            else { // r >= nums.size() || prod * nums[r] >= k
                res += (r-l);
                prod /= nums[l];
                l ++;
            }
        }

        return res;
    }
};

int main() {

    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    cout << Solution().numSubarrayProductLessThanK(nums1, k1) << endl;

    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    cout << Solution().numSubarrayProductLessThanK(nums2, k2) << endl;

    vector<int> nums3 = {1, 1, 6, 1, 1, 8};
    int k3 = 5;
    cout << Solution().numSubarrayProductLessThanK(nums3, k3) << endl;


    for(int i = 1 ; i <= 5 ; i ++) {
        vector<int> nums(i, 1);
        int k = 5;

        int a = i, b = i + 1;
        if(a % 2 == 0) a /= 2;
        else b /= 2;
        if(Solution().numSubarrayProductLessThanK(nums, k) != a * b)
            cout << "Error on " << i << endl;
    }

    return 0;
}