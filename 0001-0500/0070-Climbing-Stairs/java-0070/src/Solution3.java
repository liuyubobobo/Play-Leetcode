/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-20

/// Fibonacci Number
/// We can see from the transition equation that
/// climbStairs(i) is the (i+1)th fibonacci number
/// where f0 = 0, f(1) = 1, f(2) = 1, f(3) = 2...
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
public class Solution3 {

    public int climbStairs(int n) {

        if(n <= 0)
            throw new IllegalArgumentException("n must be greater than zero");

        if(n == 1)
            return 1;

        int prev = 1, cur = 1;
        for(int i = 3 ; i <= n + 1; i ++){
            int f = cur + prev;
            prev = cur;
            cur = f;
        }
        return cur;
    }

    public static void main(String[] args) {

        System.out.println((new Solution3()).climbStairs(10));
    }
}
