/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

import java.util.*;
import java.util.HashMap;
import javafx.util.Pair;

/// Using Tree Set
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution1 {

    private class PairComparator implements Comparator<Pair<Integer, Integer>>{

        @Override
        public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2){
            if(p1.getKey() != p2.getKey())
                return p2.getKey() - p1.getKey();
            return p1.getValue() - p2.getValue();
        }
    }

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

        TreeSet<Pair<Integer, Integer>> set = new TreeSet<Pair<Integer, Integer>>(new PairComparator());
        for(Integer key: freq.keySet())
            set.add(new Pair(freq.get(key), key));

        ArrayList<Integer> res = new ArrayList<Integer>();
        for(Pair<Integer, Integer> p: set){
            res.add(p.getValue());
            if(res.size() == k)
                break;
        }

        return res;
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
