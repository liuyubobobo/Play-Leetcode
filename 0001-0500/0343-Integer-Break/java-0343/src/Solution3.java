/// Source : https://leetcode.com/problems/integer-break/description/
/// Author : liuyubobobo
/// Time   : 2019-07-24

/// Dynamic Programming
/// Deal with 2, 3 and 4 seperately
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
public class Solution3 {

    public int integerBreak(int n) {

        if(n < 1)
            throw new IllegalArgumentException("n should be greater than zero");
        if(n == 2) return 1;
        if(n == 3) return 2;

        int[] memo = new int[n+1];
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 3;
        for(int i = 2 ; i <= n ; i ++)
            for(int j = 1 ; j <= i / 2 ; j ++)
                memo[i] = Math.max(memo[i], memo[j] * memo[i - j]);

        return memo[n];
    }

    public static void main(String[] args) {

        System.out.println((new Solution2()).integerBreak(2));
        System.out.println((new Solution2()).integerBreak(10));
    }
}
