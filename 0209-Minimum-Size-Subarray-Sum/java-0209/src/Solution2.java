/// https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-13

// Sum Prefix + Binary Search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
public class Solution2 {

    public int minSubArrayLen(int s, int[] nums) {

        if(s <= 0 || nums == null)
            throw new IllegalArgumentException("Illigal Arguments");

        int[] sums = new int[nums.length + 1];
        sums[0] = 0;
        for(int i = 1 ; i <= nums.length ; i ++)
            sums[i] = sums[i-1] + nums[i-1];

        int res = nums.length + 1;
        for(int l = 0 ; l < nums.length - 1 ; l ++){
            // Unfortunately, there's no lowerBound method in Java，
            // We need to implement our own lowerBound :(
            int r = lowerBound(sums, sums[l] + s);
            if(r != sums.length)
                res = Math.min(res, r - l);
        }

        if(res == nums.length + 1)
            return 0;
        return res;
    }

    // Find the smallest number index which is larger or equal to target
    // in a sorted array nums
    // If there's no such a number, in which all number in nums are smaller than target
    // return nums.length
    private int lowerBound(int[] nums, int target){

        if(nums == null /*|| !isSorted(nums)*/)
            throw new IllegalArgumentException("Illegal argument nums in lowerBound.");

        int l = 0, r = nums.length;
        while(l != r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    private boolean isSorted(int[] nums){
        for(int i = 1 ; i < nums.length ; i ++)
            if(nums[i] < nums[i-1])
                return false;
        return true;
    }

    public static void main(String[] args) {

        int[] nums = {2, 3, 1, 2, 4, 3};
        int s = 7;
        System.out.println((new Solution2()).minSubArrayLen(s, nums));
    }
}
