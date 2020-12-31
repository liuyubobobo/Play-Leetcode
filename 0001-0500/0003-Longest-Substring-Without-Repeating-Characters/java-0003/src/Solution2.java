/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

// Sliding Window
// Another Implementation
//
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
public class Solution2 {
    public int lengthOfLongestSubstring(String s) {

        int[] freq = new int[256];

        int l = 0, r = -1; // sliding window: s[l...r]
        int res = 0;

        while(r + 1 < s.length()){

            while(r + 1 < s.length() && freq[s.charAt(r+1)] == 0)
                freq[s.charAt(++r)] ++;

            res = Math.max(res, r - l + 1);

            if(r + 1 < s.length()){
                freq[s.charAt(++r)] ++;
                assert(freq[s.charAt(r)] == 2);
                while(l <= r && freq[s.charAt(r)] == 2)
                    freq[s.charAt(l++)] --;
            }
        }

        return res;
    }

    public static void main(String[] args) {

        System.out.println((new Solution2()).lengthOfLongestSubstring( "abcabcbb" ));
        System.out.println((new Solution2()).lengthOfLongestSubstring( "bbbbb" ));
        System.out.println((new Solution2()).lengthOfLongestSubstring( "pwwkew" ));
        System.out.println((new Solution2()).lengthOfLongestSubstring( "" ));
    }
}
