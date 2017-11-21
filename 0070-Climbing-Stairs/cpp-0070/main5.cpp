/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-20

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

/// Fibonacci Number - Closed Formula
/// Fn = 1/sqrt(5) * {[(1+sqrt(5))/2]^n - [(1-sqrt(5))/2]^n}
///
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {

public:
    int climbStairs(int n) {

        assert(n > 0);

        if(n == 1)
            return 1;

        double sqrt5 = sqrt(5.0);
        return (int)((pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1)) / sqrt5);
    }

};

int main() {

    cout << Solution().climbStairs(10) << endl;
    return 0;
}