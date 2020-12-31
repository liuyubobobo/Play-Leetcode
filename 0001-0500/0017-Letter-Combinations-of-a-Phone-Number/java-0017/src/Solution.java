/// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

import java.util.List;
import java.util.ArrayList;

/// Backtracking
/// Time Complexity: O(2^len(s))
/// Space Complexity: O(len(s))
class Solution {

    private String letterMap[] = {
                " ",    //0
                "",     //1
                "abc",  //2
                "def",  //3
                "ghi",  //4
                "jkl",  //5
                "mno",  //6
                "pqrs", //7
                "tuv",  //8
                "wxyz"  //9
    };

    private ArrayList<String> res;

    public List<String> letterCombinations(String digits) {

        res = new ArrayList<String>();
        if(digits.equals(""))
            return res;

        findCombination(digits, 0, "");
        return res;
    }

    private void findCombination(String digits, int index, String s){

        if(index == digits.length()){
            res.add(s);
            return;
        }

        Character c = digits.charAt(index);
        assert  c.compareTo('0') >= 0 &&
                c.compareTo('9') <= 0 &&
                c.compareTo('1') != 0;
        String letters = letterMap[c - '0'];
        for(int i = 0 ; i < letters.length() ; i ++)
            findCombination(digits, index+1, s + letters.charAt(i));

        return;
    }

    private static void printList(List<String> list){
        for(String s: list)
            System.out.println(s);
    }

    public static void main(String[] args) {

        printList((new Solution()).letterCombinations("234"));
    }
}
