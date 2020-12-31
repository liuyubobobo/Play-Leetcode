/// Source : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
/// Author : liuyubobobo
/// Time   : 2017-10-19

import java.util.*;
import java.util.stream.IntStream;

/// Dynamic Programming
///
/// Time Complexity: O((2^len(nums)) * len(nums))
/// Space Complexity: O((2^len(nums)))
public class Solution3 {

    public boolean canPartitionKSubsets(int[] nums, int k) {

        int sum = IntStream.of(nums).sum();
        if(sum % k != 0)
            return false;

        int subsum = sum / k;

        Arrays.sort(nums);
        if(nums[nums.length-1] > subsum)
            return false;

        int len = (1<<nums.length);

        int[] todo = new int[len];
        boolean[] visited = new boolean[len];
        for(int i = 0 ; i < len ; i ++)
            todo[i] = subsum;

        visited[0] = true;
        for(int i = 0 ; i < len ; i ++){

            // i should be visited here
            // if !visited[i], means the state of i can not construct to a solution!
            if(!visited[i])
                continue;

            for(int j = 0 ; j < nums.length ; j ++)
                if((i & (1<<j)) == 0){
                    int newState = (i | (1<<j));
                    if(!visited[newState] && todo[i] >= nums[j]){
                        todo[newState] = todo[i] - nums[j];
                        if(todo[newState] == 0)
                            todo[newState] = subsum;
                        visited[newState] = true;
                    }
                }
        }

        int lastState = (1<<nums.length) - 1;
        return visited[lastState] && todo[lastState] == subsum;
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