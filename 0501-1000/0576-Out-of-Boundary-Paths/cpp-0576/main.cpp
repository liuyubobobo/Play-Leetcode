/// Source : https://leetcode.com/problems/out-of-boundary-paths/
/// Author : liuyubobobo
/// Time   : 2021-06-24

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(m * n * k)
/// Space Complexity: O(m * n * k)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const int MOD = 1e9 + 7;
    int R, C;

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        R = m, C = n;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dfs(dp, startRow, startColumn, maxMove);
    }

private:
    int dfs(vector<vector<vector<int>>>& dp, int x, int y, int k){

        if(x < 0 || x >= R || y < 0 || y >= C)
            return 1;

        if(k == 0) return 0;

        assert(x >= 0 && x < R && y >= 0 && y < C);
        if(dp[x][y][k] != -1) return dp[x][y][k];

        int res = 0;
        for(int d = 0; d < 4; d ++)
            res = (res + dfs(dp, x + dirs[d][0], y + dirs[d][1], k - 1)) % MOD;
        return dp[x][y][k] = res;
    }
};


int main() {

    return 0;
}
