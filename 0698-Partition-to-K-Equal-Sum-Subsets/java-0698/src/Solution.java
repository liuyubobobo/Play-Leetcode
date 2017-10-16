/// Source : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
/// Author : liuyubobobo
/// Time   : 2017-10-15

// Time Complexity: O((2^len(nums)) * len(nums) * k)
// Space Complexity: O((2^len(nums)) * k)
public class Solution {

    private int[] nums;
    private int subsum;
    private boolean[][] dp;
    private boolean[][] visited;

    public boolean canPartitionKSubsets(int[] nums, int k) {

        int sum = getSum(nums);
        if(sum % k != 0)
            return false;

        this.nums = nums;
        this.subsum = sum / k;

        int len = 1<<nums.length;

        this.dp = new boolean[len][k+1];
        this.visited = new boolean[len][k+1];

        return solve(0, k);
    }

    private int getSum(int[] nums){
        int sum = 0;
        for(int i = 0 ; i < nums.length ; i ++)
            sum += nums[i];
        return sum;
    }

    private boolean solve(int status, int left){

        if(left == 0)
            return true;

        if(visited[status][left])
            return dp[status][left];

        visited[status][left] = true;
        return dp[status][left] = findSum(status, 0, subsum, left);
    }

    private boolean findSum(int status, int startIndex, int sum, int left){

        if(sum == 0)
            return solve(status, left-1);

        for(int i = startIndex; i < nums.length ; i ++)
            if(sum >= nums[i] && ((status & (1<<i)) == 0))
                if(findSum(status|(1<<i), i+1, sum-nums[i], left))
                    return true;

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