/// Source : https://leetcode.com/problems/combinations/description/
/// Author : liuyubobobo
/// Time   : 2019-04-08

import java.util.List;
import java.util.ArrayList;


/// Get all the combinations in place
/// Find the first non-saturated element and increase it
///
/// Time Complexity: O(k * C(n, k))
/// Space Complexity: O(1)
public class Solution4 {

    public List<List<Integer>> combine(int n, int k) {

        List<List<Integer>> res = new ArrayList<>();

        int[] c = new int[k];
        for(int i = 1; i <= k; i ++)
            c[i - 1] = i;
        res.add(getList(c));

        while(c[0] != n - k + 1){

            if(c[k - 1] != n) c[k - 1] ++;
            else{
                for(int i = k - 1; i >= 0; i --)
                    if(c[i] != i + n - k + 1){
                        c[i] ++;
                        for(int j = i + 1; j < k; j ++)
                            c[j] = c[j - 1] + 1;
                        break;
                    }
            }
            res.add(getList(c));
        }
        return res;
    }

    private List getList(int[] arr){
        ArrayList<Integer> res = new ArrayList<>();
        for(int e: arr)
            res.add(e);
        return res;
    }
}
