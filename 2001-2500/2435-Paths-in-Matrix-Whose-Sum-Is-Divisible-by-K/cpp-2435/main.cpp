/// Source : https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
/// Author : liuyubobobo
/// Time   : 2022-10-09

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(R * C * k)
/// Space Complexity: O(R * C * k)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int R = grid.size(), C = grid[0].size();
        vector<vector<vector<long long>>> dp(R, vector<vector<long long>>(C, vector<long long>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;

        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++) {
                if(i == 0 && j == 0) continue;
                for (int m = 0; m < k; m++) {
                    long long t = 0;

                    int a = m - grid[i][j];
                    if (a < 0)
                        a = (a % k + k) % k;

                    if(i - 1 >= 0) t += dp[i - 1][j][a];
                    if(j - 1 >= 0) t += dp[i][j - 1][a];

                    dp[i][j][m] = t % MOD;
                }
            }
        return dp[R - 1][C - 1][0];
    }
};


int main() {

    vector<vector<int>> grid1 = {{5,2,4},{3,0,5},{0,7,2}};
    cout << Solution().numberOfPaths(grid1, 3) << '\n';
    // 2

    return 0;
}
