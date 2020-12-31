/// Source : https://leetcode.com/problems/permutations/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

import java.util.List;
import java.util.ArrayList;
import java.util.LinkedList;

/// Most Naive Recursive
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
public class Solution1 {

    private ArrayList<List<Integer>> res;
    private boolean[] used;

    public List<List<Integer>> permute(int[] nums) {

        res = new ArrayList<List<Integer>>();
        if(nums == null || nums.length == 0)
            return res;

        used = new boolean[nums.length];
        LinkedList<Integer> p = new LinkedList<Integer>();
        generatePermutation(nums, 0, p);

        return res;
    }

    private void generatePermutation(int[] nums, int index, LinkedList<Integer> p){

        if(index == nums.length){
            res.add((LinkedList<Integer>)p.clone());
            return;
        }

        for(int i = 0 ; i < nums.length ; i ++)
            if(!used[i]){
                used[i] = true;
                p.addLast(nums[i]);
                generatePermutation(nums, index + 1, p );
                p.removeLast();
                used[i] = false;
            }

        return;
    }

    private static void printList(List<Integer> list){
        for(Integer e: list)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] nums = {1, 2, 3};
        List<List<Integer>> res = (new Solution1()).permute(nums);
        for(List<Integer> list: res)
            printList(list);
    }
}
