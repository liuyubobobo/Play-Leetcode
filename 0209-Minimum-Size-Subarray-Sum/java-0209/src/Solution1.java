/// https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-13

// Sum Prefix
// Time Complexity: O(n^2)
// Space Complexity: O(n)
public class Solution1 {

    public int minSubArrayLen(int s, int[] nums) {

        if(s <= 0 || nums == null)
            throw new IllegalArgumentException("Illigal Arguments");

        int[] sums = new int[nums.length + 1];
        sums[0] = 0;
        for(int i = 1 ; i <= nums.length ; i ++)
            sums[i] = sums[i-1] + nums[i-1];

        int res = nums.length + 1;
        for(int l = 0 ; l < nums.length ; l ++)
            for(int r = l ; r < nums.length ; r ++)
                if(sums[r+1] - sums[l] >= s)
                    res = Math.min(res, r - l + 1);

        if(res == nums.length + 1)
            return 0;

        return res;
    }

    public static void main(String[] args) {

        int[] nums = {2, 3, 1, 2, 4, 3};
        int s = 7;
        System.out.println((new Solution1()).minSubArrayLen(s, nums));
    }
}
