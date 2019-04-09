/// Source : https://leetcode.com/problems/combinations/description/
/// Author : liuyubobobo
/// Time   : 2019-04-08

import java.util.List;
import java.util.ArrayList;


/// Get all the combinations in place
/// find the first j which nums[j] + 1 != nums[j + 1] and increase nums[j]
/// See here for details: https://leetcode.com/problems/combinations/solution/
///
/// Time Complexity: O(k * C(n, k))
/// Space Complexity: O(1)
public class Solution5 {

    public List<List<Integer>> combine(int n, int k) {

        List<List<Integer>> res = new ArrayList<>();

        int[] c = new int[k + 1];
        for(int i = 1; i <= k; i ++)
            c[i - 1] = i;
        c[k] = n + 1;

        int j = 0;
        while(j < k){
            res.add(getList(c));

            for(j = 0; j < k && c[j] + 1 == c[j + 1]; j ++)
                c[j] = j + 1;
            c[j] ++;
        }
        return res;
    }

    private List getList(int[] arr){
        ArrayList<Integer> res = new ArrayList<>();
        for(int i = 0; i < arr.length - 1; i ++)
            res.add(arr[i]);
        return res;
    }
}
