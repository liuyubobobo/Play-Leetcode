/// Source : https://leetcode.com/problems/unique-paths/
/// Author : liuyubobobo
/// Time   : 2019-04-02

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i ++)
            for(int j = 1; j < n; j ++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};


int main() {

    return 0;
}