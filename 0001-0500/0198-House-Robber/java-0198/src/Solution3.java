/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

/// Dynamic Programming with O(1) Space
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution3 {

    public int rob(int[] nums) {

        int n = nums.length;
        if(n == 0)
            return 0;

        int curMax = 0, preMax = 0;
        for(int i = n - 1 ; i >= 0 ; i --) {
            int temp = curMax;
            curMax = Math.max(curMax, nums[i] + preMax);
            preMax = temp;
        }
        return curMax;
    }

    public static void main(String[] args) {

        int nums[] = {2, 1};
        System.out.println((new Solution3()).rob(nums));
    }
}
