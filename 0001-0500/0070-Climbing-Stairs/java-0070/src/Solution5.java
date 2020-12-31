/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-20

/// Fibonacci Number - Closed Formula
/// Fn = 1/sqrt(5) * {[(1+sqrt(5))/2]^n - [(1-sqrt(5))/2]^n}
///
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
public class Solution5 {

    public int climbStairs(int n) {

        if(n <= 0)
            throw new IllegalArgumentException("n must be greater than zero");

        if(n == 1)
            return 1;

        double sqrt5 = Math.sqrt(5.0);
        return (int)((Math.pow((1 + sqrt5) / 2, n + 1) - Math.pow((1 - sqrt5) / 2, n + 1)) / sqrt5);
    }

    public static void main(String[] args) {

        System.out.println((new Solution5()).climbStairs(10));
    }
}
