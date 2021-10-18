/// Source : https://leetcode.com/problems/maximum-alternating-subarray-sum/
/// Author : liuyubobobo
/// Time   : 2021-10-18

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {

        int n = nums.size();

        vector<long long> even(n, nums[0]);
        for(int i = 1; i < n; i ++)
            if(i % 2) even[i] = even[i - 1] - nums[i];
            else even[i] = even[i - 1] + nums[i];

        vector<long long> odd(n, 0);
        for(int i = 1; i < n; i ++)
            if(i % 2) odd[i] = odd[i - 1] + nums[i];
            else odd[i] = odd[i - 1] - nums[i];

        long long even_max = LONG_LONG_MIN, odd_max = LONG_LONG_MIN;
        long long res = LONG_LONG_MIN;
        for(int i = n - 1; i >= 0; i --){
            even_max = max(even_max, even[i]);
            odd_max = max(odd_max, odd[i]);
            if(i % 2 == 0)
                res = max(res, even_max - (i - 1 >= 0 ? even[i - 1] : 0));
            else
                res = max(res, odd_max - (i - 1 >= 0 ? odd[i - 1] : 0));
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {3, -1, 1, 2};
    cout << Solution().maximumAlternatingSubarraySum(nums1) << endl;
    // 5

    vector<int> nums2 = {2,2,2,2,2};
    cout << Solution().maximumAlternatingSubarraySum(nums2) << endl;
    // 2

    vector<int> nums3 = {1};
    cout << Solution().maximumAlternatingSubarraySum(nums3) << endl;
    // 1

    vector<int> nums4 = {5, 100};
    cout << Solution().maximumAlternatingSubarraySum(nums4) << endl;
    // 100

    return 0;
}
