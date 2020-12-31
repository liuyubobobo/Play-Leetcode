/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int climbStairs(int n) {

        assert(n > 0);

        vector<int> memo(n + 1, -1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2 ; i <= n ; i ++)
            memo[i] = memo[i - 1] + memo[i - 2];
        return memo[n];
    }
};

int main() {

    cout << Solution().climbStairs(10) << endl;
    return 0;
}