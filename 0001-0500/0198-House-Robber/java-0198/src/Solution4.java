/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

import java.util.Arrays;

/// Memory Search
/// Another way to define the states
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution4 {

    // the max profit for robbing nums[0...i]
    private int[] memo;

    public int rob(int[] nums) {
        memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return tryRob(nums, nums.length - 1);
    }

    private int tryRob(int[] nums, int index){

        if(index < 0)
            return 0;

        if(memo[index] != -1)
            return memo[index];

        return memo[index] =
                Math.max(tryRob(nums, index - 1),
                        nums[index] + tryRob(nums, index - 2));
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution4()).rob(nums));
    }
}
