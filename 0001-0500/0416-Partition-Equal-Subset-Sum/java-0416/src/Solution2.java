/// Source : https://leetcode.com/problems/partition-equal-subset-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

import java.util.Arrays;

/// Dynamic Programming
/// Time Complexity: O(len(nums) * O(sum(nums)))
/// Space Complexity: O(len(nums) * O(sum(nums)))
public class Solution2 {

    public boolean canPartition(int[] nums) {

        int sum = 0;
        for(int i = 0 ; i < nums.length ; i ++){
            if(nums[i] <= 0)
                throw new IllegalArgumentException("numbers in nums must be greater than zero.");
            sum += nums[i];
        }

        if(sum % 2 == 1)
            return false;

        int n = nums.length;
        int C = sum / 2;

        boolean[] memo = new boolean[C + 1];
        for(int i = 0 ; i <= C ; i ++)
            memo[i] = (nums[0] == i);

        for(int i = 1 ; i < n ; i ++)
            for(int j = C; j >= nums[i] ; j --)
                memo[j] = memo[j] || memo[j - nums[i]];

        return memo[C];
    }

    private static void printBool(boolean res){
        System.out.println(res ? "True" : "False");
    }

    public static void main(String[] args) {

        int[] nums1 = {1, 5, 11, 5};
        printBool((new Solution2()).canPartition(nums1));

        int[] nums2 = {1, 2, 3, 5};
        printBool((new Solution2()).canPartition(nums2));
    }
}
