/// Source : https://leetcode.com/problems/integer-break/description/
/// Author : liuyubobobo
/// Time   : 2017-11-19

/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
public class Solution2 {

    public int integerBreak(int n) {

        if(n < 1)
            throw new IllegalArgumentException("n should be greater than zero");

        int[] memo = new int[n+1];
        memo[1] = 1;
        for(int i = 2 ; i <= n ; i ++)
            for(int j = 1 ; j <= i - 1 ; j ++)
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);

        return memo[n];
    }

    private int max3(int a, int b, int c){
        return Math.max(a, Math.max(b, c));
    }

    public static void main(String[] args) {

        System.out.println((new Solution2()).integerBreak(2));
        System.out.println((new Solution2()).integerBreak(10));
    }
}
