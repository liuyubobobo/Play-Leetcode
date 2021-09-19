/// Source : https://leetcode.com/problems/distinct-subsequences/description/
/// Author : liuyubobobo
/// Time   : 2018-04-23

/// Dynamic Programming
/// Time Complexity: O(s * t)
/// Space Complexity: O(t)
public class Solution2 {

    public int numDistinct(String s, String t) {

        int[] dp = new int[t.length() + 1];
        dp[0] = 1;

        for(int i = 1 ; i <= s.length() ; i ++)
            for(int j = t.length() ; j >= 1 ; j --)
                if(s.charAt(i - 1) == t.charAt(j - 1))
                    dp[j] += dp[j - 1];


        return dp[t.length()];
    }

    public static void main(String[] args) {

        String s1 = "rabbbit", t1 = "rabbit";
        System.out.println((new Solution()).numDistinct(s1, t1));
        // 3

        String s2 = "babgbag", t2 = "bag";
        System.out.println((new Solution()).numDistinct(s2, t2));
        // 5
    }
}
