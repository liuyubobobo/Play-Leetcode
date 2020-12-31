/// https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-03-03

// Brute Force + Greedy
// Time Complexity: O(n^2)
// Space Complexity: O(1)
public class Solution2 {

    public int minSubArrayLen(int s, int[] nums) {

        if(s <= 0 || nums == null)
            throw new IllegalArgumentException("Illigal Arguments");

        int res = nums.length + 1;
        for(int l = 0 ; l < nums.length ; l ++) {
            int sum = 0;
            for (int r = l; r < nums.length; r++){
                sum += nums[r];
                if(sum >= s){
                    res = Math.min(res, r - l + 1);
                    break;
                }
            }
        }

        return res == nums.length + 1 ? 0 : res;
    }

    public static void main(String[] args) {

        int[] nums = {2, 3, 1, 2, 4, 3};
        int s = 7;
        System.out.println((new Solution2()).minSubArrayLen(s, nums));
    }
}
