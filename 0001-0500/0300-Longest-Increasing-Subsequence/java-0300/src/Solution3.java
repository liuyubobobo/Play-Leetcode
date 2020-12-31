/// Source : https://leetcode.com/problems/longest-increasing-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

import java.util.Arrays;

/// Dynamic Programming
/// Best Solution for LIS Problem
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
public class Solution3 {

    public int lengthOfLIS(int[] nums) {

        if(nums.length == 0)
            return 0;

        // dp[i] is the last num for length i increasing sequence
        int dp[] = new int[nums.length + 1];
        Arrays.fill(dp, Integer.MIN_VALUE);

        int len = 1;
        dp[1] = nums[0];
        for(int i = 1 ; i < nums.length ; i ++)
            if(nums[i] > dp[len]){
                len ++;
                dp[len] = nums[i];
            }
            else{
                int index = lowerBound(dp, 0, len, nums[i]);
                if(dp[index] != nums[i])
                    dp[index] = Math.min(dp[index], nums[i]);
            }

        return len;
    }

    private int lowerBound(int[] arr, int l, int r, int target){

        int left = l, right = r + 1;
        while(left != right){
            int mid = left + (right - left) / 2;
            if(arr[mid] >= target)
                right = mid;
            else // arr[mid] < target
                left = mid + 1;
        }
        return left;
    }

    public static void main(String[] args) {

        int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18};
        System.out.println((new Solution3()).lengthOfLIS(nums1));
        // 4

        // ---

        int nums2[] = {4, 10, 4, 3, 8, 9};
        System.out.println((new Solution3()).lengthOfLIS(nums2));
        // 3

        // ---

        int nums3[] = {2, 2};
        System.out.println((new Solution3()).lengthOfLIS(nums3));
        // 1

        // ---

        int nums4[] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
        System.out.println((new Solution3()).lengthOfLIS(nums4));
        // 6
    }
}
