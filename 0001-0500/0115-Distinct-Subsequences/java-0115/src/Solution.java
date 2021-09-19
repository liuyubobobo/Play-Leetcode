/// Source : https://leetcode.com/problems/distinct-subsequences/description/
/// Author : liuyubobobo
/// Time   : 2018-04-23

/// Dynamic Programming
/// Time Complexity: O(s * t)
/// Space Complexity: O(s * t)
public class Solution {
    public int numDistinct(String s, String t) {

        int[][] dp = new int[s.length() + 1][t.length() + 1];
        for(int i = 0 ; i <= s.length() ; i ++)
            dp[i][0] = 1;

        for(int i = 1 ; i <= s.length() ; i ++)
            for(int j = 1 ; j <= t.length() ; j ++){
                dp[i][j] = dp[i - 1][j];
                if(s.charAt(i - 1) == t.charAt(j - 1))
                    dp[i][j] += dp[i - 1][j - 1];
            }

        return dp[s.length()][t.length()];
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
