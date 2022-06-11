/// Source : https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
/// Author : liuyubobobo
/// Time   : 2022-06-11

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int l = 0, r = -1, n = nums.size();
        long long cur_sum = 0, res = 0;
        while(l < n){
            if(r + 1 < n && 1ll * (cur_sum + nums[r + 1]) * (r + 1 - l + 1) < k){
                r ++;
                cur_sum += nums[r];
            }
            else{
                if(l <= r){
                    res += (r - l + 1);
                    cur_sum -= nums[l];
                }
                l ++;
                r = max(r, l - 1);
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, 1, 4, 3, 5};
    cout << Solution().countSubarrays(nums1, 10) << '\n';
    // 6

    vector<int> nums2 = {1, 1, 1};
    cout << Solution().countSubarrays(nums2, 5) << '\n';
    // 5

    vector<int> nums3 = {2, 1, 4, 3, 5};
    cout << Solution().countSubarrays(nums3, 3) << '\n';
    // 2

    return 0;
}
