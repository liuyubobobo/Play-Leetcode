/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

/// Dynamic Programming with O(1) space
/// Another way to define the states
/// Time Complexity: O(n)
/// Space Complexity: O(1)
public class Solution6 {

    public int rob(int[] nums) {

        int n = nums.length;
        if(n == 0)
            return 0;

        int curMax = 0, preMax = 0;
        for(int i = 0 ; i < n ; i ++) {
            int temp = curMax;
            curMax = Math.max(curMax, nums[i] + preMax);
            preMax = temp;
        }
        return curMax;
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution6()).rob(nums));
    }
}
