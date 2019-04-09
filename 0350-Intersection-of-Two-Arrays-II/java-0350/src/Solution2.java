/// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
/// Author : liuyubobobo
/// Time   : 2019-04-08

import java.util.Arrays;
import java.util.ArrayList;


/// Sorting and Two Pointers
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
public class Solution2 {

    public int[] intersect(int[] nums1, int[] nums2) {

        Arrays.sort(nums1);
        Arrays.sort(nums2);

        ArrayList<Integer> res = new ArrayList<>();

        int i = 0, j = 0;
        while(i < nums1.length && j < nums2.length){

            if(nums1[i] == nums2[j]){
                res.add(nums1[i]);
                i ++;
                j ++;
            }
            else if(nums1[i] < nums2[j]) i ++;
            else j ++;
        }

        int[] ret = new int[res.size()];
        int index = 0;
        for(Integer num: res)
            ret[index++] = num;

        return ret;
    }

    private static void printArr(int[] arr){
        for(int e: arr)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] nums1 = {1, 2, 2, 1};
        int[] nums2 = {2, 2};
        int[] res = (new Solution()).intersect(nums1, nums2);
        printArr(res);
    }
}
