/// Source : https://leetcode.com/problems/minimum-falling-path-sum-ii/
/// Author : liuyubobobo
/// Time   : 2023-08-09

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(n, grid, 0, n, dp);
    }

private:
    int dfs(int n, const vector<vector<int>>& grid, int row, int last_c, vector<vector<int>>& dp) {

        if (row == n) return 0;
        if (dp[row][last_c] != -1) return dp[row][last_c];

        int res = INT_MAX;
        for (int j = 0; j < n; j ++) {
            if (j == last_c) continue;
            res = min(res, grid[row][j] + dfs(n, grid, row + 1, j, dp));
        }
        return dp[row][last_c] = res;
    }
};


int main() {

    return 0;
}
