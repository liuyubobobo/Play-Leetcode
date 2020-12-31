/// Source : https://leetcode.com/problems/fibonacci-number/
/// Author : liuyubobobo
/// Time   : 2019-01-09

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int fib(int N) {

        vector<int> dp(N + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= N; i ++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[N];
    }
};


int main() {

    return 0;
}