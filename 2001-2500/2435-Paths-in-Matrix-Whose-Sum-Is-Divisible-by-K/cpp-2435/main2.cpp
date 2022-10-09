/// Source : https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
/// Author : liuyubobobo
/// Time   : 2022-10-09

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(R * C * k)
/// Space Complexity: O(R * C * k)
class Solution {

private:
    const long long MOD = 1e9 + 7;
    int R, C, k;

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        R = grid.size(), C = grid[0].size();
        this->k = k;
        vector<vector<vector<long long>>> dp(R, vector<vector<long long>>(C, vector<long long>(k, -1)));

        return dfs(grid, 0, 0, grid[0][0] % k, dp);
    }

private:
    long long dfs(const vector<vector<int>>& grid, int x, int y, int m,
                  vector<vector<vector<long long>>>& dp){

        if(x == R - 1 && y == C - 1) return m == 0;
        if(dp[x][y][m] != -1) return dp[x][y][m];

        long long res = 0;
        if(x + 1 < R) res += dfs(grid, x + 1, y, (m + grid[x + 1][y]) % k, dp);
        if(y + 1 < C) res += dfs(grid, x, y + 1, (m + grid[x][y + 1]) % k, dp);
        return dp[x][y][m] = res % MOD;
    }
};


int main() {

    vector<vector<int>> grid1 = {{5,2,4},{3,0,5},{0,7,2}};
    cout << Solution().numberOfPaths(grid1, 3) << '\n';
    // 2

    return 0;
}
