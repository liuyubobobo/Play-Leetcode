/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-20

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Fibonacci Number
/// We can see from the transition equation that
/// climbStairs(i) is the (i+1)th fibonacci number
/// where f0 = 0, f(1) = 1, f(2) = 1, f(3) = 2...
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int climbStairs(int n) {

        assert(n > 0);

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
};

int main() {

    cout << Solution().climbStairs(10) << endl;
    return 0;
}