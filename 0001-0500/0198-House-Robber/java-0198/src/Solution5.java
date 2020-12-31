/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

/// Dynamic Programming
/// Another way to define the states
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution5 {

    public int rob(int[] nums) {

        int n = nums.length;
        if(n == 0)
            return 0;

        // the max profit for robbing nums[0...i]
        int[] memo = new int[nums.length];
        memo[0] = nums[0];
        for(int i = 1 ; i < n ; i ++)
            memo[i] = Math.max(memo[i - 1],
                    nums[i] + (i - 2 >= 0 ? memo[i - 2] : 0));

        return memo[n-1];
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution5()).rob(nums));
    }
}
