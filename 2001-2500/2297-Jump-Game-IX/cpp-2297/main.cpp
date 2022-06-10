/// Source : https://leetcode.com/problems/jump-game-ix/
/// Author : liuyubobobo
/// Time   : 2022-06-09

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack + DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {

        int n = nums.size();

        vector<int> right_larger_or_equal(n, n);
        vector<int> stack;
        for(int i = n - 1; i >= 0; i --){
            while(!stack.empty() && nums[i] > nums[stack.back()]) stack.pop_back();
            if(!stack.empty()) right_larger_or_equal[i] = stack.back();
            stack.push_back(i);
        }
//        for(int e: right_larger_or_equal) cout << e << ' '; cout << '\n';

        vector<int> right_smaller(n, n);
        stack.clear();
        for(int i = n - 1; i >= 0; i --){
            while(!stack.empty() && nums[i] <= nums[stack.back()]) stack.pop_back();
            if(!stack.empty()) right_smaller[i] = stack.back();
            stack.push_back(i);
        }
//        for(int e: right_smaller) cout << e << ' '; cout << '\n';

        vector<long long> dp(n, LONG_LONG_MAX / 2);
        dp[0] = 0;
        for(int i = 0; i < n; i ++){
            int to = right_larger_or_equal[i];
            if(to < n)
                dp[to] = min(dp[to], dp[i] + costs[to]);

            to = right_smaller[i];
            if(to < n)
                dp[to] = min(dp[to], dp[i] + costs[to]);
        }
        return dp.back();
    }
};


int main() {

    vector<int> nums1 = {3, 2, 4, 4, 1}, costs1 = {3, 7, 6, 4, 2};
    cout << Solution().minCost(nums1, costs1) << '\n';
    // 8

    vector<int> nums2 = {0, 1, 2}, costs2 = {1, 1, 1};
    cout << Solution().minCost(nums2, costs2) << '\n';
    // 2

    return 0;
}
