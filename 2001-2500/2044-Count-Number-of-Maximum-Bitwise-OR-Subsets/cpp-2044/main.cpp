/// Source : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
/// Author : liuyubobobo
/// Time   : 2021-10-16

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int t = 0;
        for(int e: nums) t |= e;

        int n = nums.size(), res = 0;
        vector<int> dp(1 << n, 0);
        for(int state = 1; state < (1 << n); state ++){
            int p = __builtin_ffs(state) - 1;
            dp[state] = dp[state - (1 << p)] | nums[p];
            res += dp[state] == t;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {3, 1};
    cout << Solution().countMaxOrSubsets(nums1) << endl;
    // 2

    vector<int> nums2 = {2, 2, 2};
    cout << Solution().countMaxOrSubsets(nums2) << endl;
    // 7

    vector<int> nums3 = {3, 2, 1, 5};
    cout << Solution().countMaxOrSubsets(nums3) << endl;
    // 6

    return 0;
}
