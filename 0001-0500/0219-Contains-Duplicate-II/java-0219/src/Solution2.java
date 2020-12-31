/// Source : https://leetcode.com/problems/contains-duplicate-ii/description/
/// Author : liuyubobobo
/// Time   : 2019-04-10

import java.util.HashMap;

/// Using Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution2 {

    public boolean containsNearbyDuplicate(int[] nums, int k) {

        if(nums == null || nums.length <= 1)
            return false;

        if(k <= 0)
            return false;

        HashMap<Integer, Integer> record = new HashMap<>();
        record.put(nums[0], 0);
        for(int i = 1; i < nums.length; i ++){
            if(record.containsKey(nums[i]) && i - record.get(nums[i]) <= k)
                return true;

            record.put(nums[i], i);
        }

        return false;
    }

    private static void printBool(boolean b){
        System.out.println(b ? "True" : "False");
    }

    public static void main(String[] args) {

        int[] nums = {1, 2, 1};
        int k = 1;
        printBool((new Solution()).containsNearbyDuplicate(nums, k));
    }
}
