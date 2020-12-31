/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

import java.util.Arrays;

// Sliding Window
// Using last[c] to record the last occurance of character c
// Using last[c] to quickly move the pointer l
// only r moved from left to right, Using n times calculation of res instead of 2*n times
//
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
public class Solution3 {

    public int lengthOfLongestSubstring(String s) {

        int[] last = new int[256];
        Arrays.fill(last, -1);

        int l = 0, r = -1; // sliding window: s[l...r]
        int res = 0;
        while(r + 1 < s.length()){

            r ++;
            if(last[s.charAt(r)] != -1)
                l = Math.max(l, last[s.charAt(r)] + 1);

            res = Math.max(res, r - l + 1);
            last[s.charAt(r)] = r;
        }

        return res;
    }

    public static void main(String[] args) {

        System.out.println((new Solution3()).lengthOfLongestSubstring( "abcabcbb" ));
        System.out.println((new Solution3()).lengthOfLongestSubstring( "bbbbb" ));
        System.out.println((new Solution3()).lengthOfLongestSubstring( "pwwkew" ));
        System.out.println((new Solution3()).lengthOfLongestSubstring( "" ));
    }
}
