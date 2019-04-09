/// Source : https://leetcode.com/problems/combinations/description/
/// Author : liuyubobobo
/// Time   : 2019-04-08

import java.util.List;
import java.util.ArrayList;


/// Using bit mask
/// Time Complexity: O(2^n * n)
/// Space Complexity: O(1)
public class Solution3 {

    public List<List<Integer>> combine(int n, int k) {

        List<List<Integer>> res = new ArrayList<>();

        int LIMIT = (1 << n);
        for(int i = 0; i < LIMIT; i ++){
            List lst = getCombination(i);
            if(lst.size() == k) res.add(lst);
        }
        return res;
    }

    private List getCombination(int num){

        ArrayList<Integer> res = new ArrayList<>();
        int i = 1;
        while (num != 0){
            if(num % 2 == 1) res.add(i);
            i ++;
            num /= 2;
        }
        return res;
    }
}
