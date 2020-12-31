/// Source : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
/// Author : liuyubobobo
/// Time   : 2017-10-15

import java.util.*;
import java.util.stream.IntStream;

// Time Complexity: O((2^len(nums)) * len(nums) * k)
// Space Complexity: O((2^len(nums)) * k)
public class Solution {

    private int[] nums;
    private int subsum;
    private boolean[][] dp;
    private boolean[][] visited;

    public boolean canPartitionKSubsets(int[] nums, int k) {

        int sum = IntStream.of(nums).sum();
        if(sum % k != 0)
            return false;

        this.nums = nums;
        this.subsum = sum / k;

        Arrays.sort(nums);
        if(nums[nums.length-1] > subsum)
            return false;

        int len = 1<<nums.length;

        this.dp = new boolean[len][k+1];
        this.visited = new boolean[len][k+1];

        return solve(0, k);
    }

    private boolean solve(int state, int left){

        if(left == 0)
            return true;

        if(visited[state][left])
            return dp[state][left];

        visited[state][left] = true;
        return dp[state][left] = findSum(state, 0, subsum, left);
    }

    private boolean findSum(int state, int startIndex, int todo, int left){

        if(todo == 0)
            return solve(state, left-1);

        for(int i = startIndex; i < nums.length ; i ++)
            if(todo >= nums[i] ){
                if(((state & (1<<i)) == 0) &&
                        findSum(state|(1<<i), i+1, todo-nums[i], left))
                    return true;
            }
            else
                break;

        return false;
    }

    public static void main(String[] args) {

        int nums1[] = {4, 3, 2, 3, 5, 2, 1};
        int k1 = 4;
        if((new Solution()).canPartitionKSubsets(nums1, k1))
            System.out.println("True");
        else
            System.out.println("False");

        int nums2[] = {71,85,99,110,27,47,8,83,72,24,52,17,99};
        int k2 = 13;
        if((new Solution()).canPartitionKSubsets(nums2, k2))
            System.out.println("True");
        else
            System.out.println("False");

        int nums3[] = {39, 73, 52, 3, 9370};
        int k3 = 3;
        if((new Solution()).canPartitionKSubsets(nums3, k3))
            System.out.println("True");
        else
            System.out.println("False");
    }
}