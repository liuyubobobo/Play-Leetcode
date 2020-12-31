/// Source : https://leetcode.com/problems/alphabet-board-path/
/// Author : liuyubobobo
/// Time   : 2019-07-27

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int tribonacci(int n) {

        if(n == 0) return 0;
        if(n == 1 | n == 2) return 1;
        vector<int> dp(n + 1, 0);
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; i ++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
};


int main() {

    return 0;
}