/// Source : https://leetcode.com/problems/generate-parentheses/
/// Author : penpenps
/// Time   : 2019-05-28

import java.util.*;

/// Recursive with "(" and ")" separately and guarantee open and close num is equal
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)

public class Solution1 {
    public void helper(List<String> ans, String str, int open, int close, int max) {
        if(str.length() == 2*max){
            ans.add(str);
            return;
        }

        if(open < max)
            helper(ans, str+"(", open+1, close, max);
        if(close < open)
            helper(ans, str+")", open, close+1, max);
    }
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        helper(ans, "", 0, 0, n);
        return ans;
    }

    private static void printList(List<String> list){
        for(String e: list)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        int n = 3;
        List<String> res = (new Solution1()).generateParenthesis(n);
        printList(res);
    }
}
