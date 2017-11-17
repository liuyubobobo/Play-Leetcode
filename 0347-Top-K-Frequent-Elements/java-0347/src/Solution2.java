/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

import java.util.*;
import java.util.HashMap;
import javafx.util.Pair;
import java.util.Collections;

/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution2 {

    public List<Integer> topKFrequent(int[] nums, int k) {

        if(k <= 0)
            throw new IllegalArgumentException("k should be greater than 0");

        HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
        for(int i = 0 ; i < nums.length ; i ++)
            if(freq.containsKey(nums[i]))
                freq.put(nums[i], freq.get(nums[i]) + 1);
            else
                freq.put(nums[i], 1);

        if(k > freq.size())
            throw new IllegalArgumentException("k should be less than the number of unique numbers in nums");

        ArrayList<Integer> res = new ArrayList<Integer>();
        for(Integer key: freq.keySet())
            res.add(key);

        Collections.sort(res, (a, b) -> {
            if(freq.get(a) != freq.get(b))
                return freq.get(b) - freq.get(a);
            return a - b;
        });

        return res.subList(0, k);
    }

    private static void printList(List<Integer> nums){
        for(Integer num: nums)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] nums = {1, 1, 1, 2, 2, 3};
        int k = 2;
        printList((new Solution3()).topKFrequent(nums, k));
    }
}
