/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-20

/// Fibonacci Number - Binets Method
/// | F(n+1) F(n)   | = | 1 1 |^n
/// | F(n)   F(n-1) |   | 1 0 |
///
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
public class Solution4 {

    public int climbStairs(int n) {

        if(n <= 0)
            throw new IllegalArgumentException("n must be greater than zero");

        if(n == 1)
            return 1;

        int[][] base = {{1, 1}, {1, 0}};
        return matrix_pow(base, n)[0][0];
    }

    private int[][] matrix_pow(int[][] m, int n){

        if(n == 1)
            return m;

        int[][] t = matrix_pow(m, n / 2);
        int[][] res = matrix_multiply(t, t);
        if(n % 2 == 1)
            return matrix_multiply(res, m);
        return res;
    }

    int[][] matrix_multiply(int[][] m1, int[][] m2){
        int[][] res = new int[2][2];
        res[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
        res[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
        res[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
        res[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
        return res;
    }

    public static void main(String[] args) {

        System.out.println((new Solution4()).climbStairs(10));
    }
}
