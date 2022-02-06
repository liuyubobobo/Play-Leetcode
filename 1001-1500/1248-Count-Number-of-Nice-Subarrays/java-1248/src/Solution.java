/// Source : https://leetcode.com/problems/count-number-of-nice-subarrays/
/// Author : liuyubobobo
/// Time   : 2022-02-06

import java.util.*;


/// Presum + Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {

        HashMap<Integer, Integer> table = new HashMap<>();
        table.put(0, 1);

        int cur = 0, res = 0;
        for(int i = 0; i < nums.length; i ++){

            cur += nums[i] % 2;

            if(table.containsKey(cur - k))
                res += table.get(cur - k);

            table.put(cur, table.getOrDefault(cur, 0) + 1);
        }
        return res;
    }
}
