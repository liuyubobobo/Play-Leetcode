/// Source : https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/description/
/// Author : liuyubobobo
/// Time   : 2023-05-12

#include <iostream>
#include <vector>

using namespace std;


/// Absolute Value Expression
/// |a - b| = max(a - b, b - a)
/// max(a, b) - c = max(a - c, b - c)
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return 0;

        long long base = 0;
        for(int i = 1; i < n; i ++) base += abs(nums[i] - nums[i - 1]);

        long long res = base;
        for(int i = 1; i < n; i ++)
            res = max(res, base - abs(nums[i] - nums[i - 1]) + abs(nums[i] - nums[0]));
        for(int i = n - 2; i >= 0; i --)
            res = max(res, base - abs(nums[i] - nums[i + 1]) + abs(nums[i] - nums[n - 1]));

        vector<int> dp(4);
        dp[0] = nums[0] + nums[1] - abs(nums[0] - nums[1]);
        dp[1] = nums[0] - nums[1] - abs(nums[0] - nums[1]);
        dp[2] = - nums[0] + nums[1] - abs(nums[0] - nums[1]);
        dp[3] = - nums[0] - nums[1] - abs(nums[0] - nums[1]);

        for(int i = 1; i + 1 < n; i ++){
            int d = 0, x= nums[i], y = nums[i + 1];
            d = max(d, dp[0] - (x + y) - abs(x - y));
            d = max(d, dp[1] - (x - y) - abs(x - y));
            d = max(d, dp[2] - (- x + y) - abs(x - y));
            d = max(d, dp[3] - (- x - y) - abs(x - y));

            res = max(res, base + d);

            dp[0] = max(dp[0], x + y - abs(x - y));
            dp[1] = max(dp[1], x - y - abs(x - y));
            dp[2] = max(dp[2], - x + y - abs(x - y));
            dp[3] = max(dp[3], - x - y - abs(x - y));
        }
        return res;
    }
};


int main() {

    return 0;
}
