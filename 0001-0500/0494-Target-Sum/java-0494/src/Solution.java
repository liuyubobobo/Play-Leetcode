/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : liuyubobobo
/// Time   : 2022-09-24
class Solution {
    public int findTargetSumWays(int[] nums, int target) {

        int sum = 0;
        for(int num: nums) sum += num;

        if(target < -sum || target > sum) return 0;

        int n = nums.length;
        int[][] dp = new int[n + 1][2 * sum + 1];

        int offset = sum;
        dp[0][0 + offset] = 1;
        for(int i = 0; i < n; i ++){
            for(int s = -sum; s <= sum; s ++){
                if(-sum <= s + nums[i] && s + nums[i] <= sum)
                    dp[i + 1][s + offset] += dp[i][s + nums[i] + offset];
                if(-sum <= s - nums[i] && s - nums[i] <= sum)
                    dp[i + 1][s + offset] += dp[i][s - nums[i] + offset];
            }
        }
        return dp[n][target + offset];
    }
}