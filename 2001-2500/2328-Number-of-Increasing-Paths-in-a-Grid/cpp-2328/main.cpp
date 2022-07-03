/// Source : https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
/// Author : liuyubobobo
/// Time   : 2022-07-02

#include <iostream>
#include <vector>

using namespace std;


/// DAG DP
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    const long long MOD = 1e9 + 7;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    int countPaths(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();

        vector<vector<long long>> dp(R, vector<long long>(C, -1));
        long long res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                res += dfs(grid, i, j, dp);
        return res % MOD;
    }

private:
    long long dfs(const vector<vector<int>>& g, int cx, int cy,
                  vector<vector<long long>>& dp){

        if(dp[cx][cy] != -1) return dp[cx][cy];

        long long res = 1;
        for(int d = 0; d < 4; d ++){
            int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
            if(!in_area(nx, ny) || g[nx][ny] <= g[cx][cy]) continue;
            res += dfs(g, nx, ny, dp);
        }

        return dp[cx][cy] = res % MOD;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<vector<int>> grid1 = {{1, 1}, {3, 4}};
    cout << Solution().countPaths(grid1) << '\n';
    // 8

    vector<vector<int>> grid2 = {{1}, {2}};
    cout << Solution().countPaths(grid2) << '\n';
    // 3

    return 0;
}
