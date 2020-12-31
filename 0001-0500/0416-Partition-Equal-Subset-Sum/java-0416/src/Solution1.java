/// Source : https://leetcode.com/problems/partition-equal-subset-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

import java.util.Arrays;

/// Memory Search
/// Time Complexity: O(len(nums) * O(sum(nums)))
/// Space Complexity: O(len(nums) * O(sum(nums)))
public class Solution1 {

    // memo[i][c]: using nums[0...i] to fill a back knapsack with space c
    private int[][] memo;

    public boolean canPartition(int[] nums) {

        int sum = 0;
        for(int i = 0 ; i < nums.length ; i ++){
            if(nums[i] <= 0)
                throw new IllegalArgumentException("numbers in nums must be greater than zero.");
            sum += nums[i];
        }

        if(sum % 2 == 1)
            return false;

        memo = new int[nums.length][sum / 2 + 1];
        for(int i = 0 ; i < nums.length ; i ++)
            Arrays.fill(memo[i], -1);
        return tryPartition(nums, nums.length - 1, sum / 2);
    }

    private boolean tryPartition(int[] nums, int index, int sum){

        if(sum == 0)
            return true;

        if(sum < 0 || index < 0)
            return false;

        if(memo[index][sum] != -1)
            return memo[index][sum] == 1;

        memo[index][sum] = (tryPartition(nums, index - 1, sum) ||
                tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;

        return memo[index][sum] == 1;
    }

    private static void printBool(boolean res){
        System.out.println(res ? "True" : "False");
    }

    public static void main(String[] args) {

        int[] nums1 = {1, 5, 11, 5};
        printBool((new Solution1()).canPartition(nums1));

        int[] nums2 = {1, 2, 3, 5};
        printBool((new Solution1()).canPartition(nums2));
    }
}
