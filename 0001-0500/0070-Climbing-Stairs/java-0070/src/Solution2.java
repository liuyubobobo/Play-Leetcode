/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution2 {

    public int climbStairs(int n) {

        if(n <= 0)
            throw new IllegalArgumentException("n must be greater than zero");

        int[] memo = new int[n + 1];
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2 ; i <= n ; i ++)
            memo[i] = memo[i - 1] + memo[i - 2];
        return memo[n];
    }

    public static void main(String[] args) {

        System.out.println((new Solution2()).climbStairs(10));
    }
}
