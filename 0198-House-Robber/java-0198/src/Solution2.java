/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution2 {

    public int rob(int[] nums) {

        int n = nums.length;
        if(n == 0)
            return 0;

        // the max profit for robbing nums[i...n)
        int[] memo = new int[nums.length];
        memo[n - 1] = nums[n - 1];
        for(int i = n - 2 ; i >= 0 ; i --)
            memo[i] = Math.max(memo[i + 1],
                               nums[i] + (i + 2 < n ? memo[i + 2] : 0));

        return memo[0];
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution2()).rob(nums));
    }
}
