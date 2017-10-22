/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/// Author : liuyubobobo
/// Time   : 2017-10-21

/// Using Sliding Window
/// Time Complexity: O(len(s))
/// Space Complexity: O(len(charset))
public class Solution {
    public int lengthOfLongestSubstring(String s) {

        int[] freq = new int[256];

        int l = 0, r = -1; //sliding window: s[l...r]
        int res = 0;

        while( r + 1 < s.length() ){

            if( r + 1 < s.length() && freq[s.charAt(r+1)] == 0 )
                freq[s.charAt(++r)] ++;
            else    //freq[s[r+1]] == 1
                freq[s.charAt(l++)] --;

            res = Math.max( res , r-l+1);
        }

        return res;
    }

    public static void main(String[] args) {
        System.out.println((new Solution()).lengthOfLongestSubstring( "abcabcbb" ));
        System.out.println((new Solution()).lengthOfLongestSubstring( "bbbbb" ));
        System.out.println((new Solution()).lengthOfLongestSubstring( "pwwkew" ));
        System.out.println((new Solution()).lengthOfLongestSubstring( "" ));
    }
}