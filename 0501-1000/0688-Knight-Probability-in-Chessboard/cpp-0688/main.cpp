/// Source : https://leetcode.com/problems/knight-probability-in-chessboard/
/// Author : liuyubobobo
/// Time   : 2022-02-16

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(k * n^2)
/// Space Complexity: O(k * n^2)
class Solution {

private:
    const int dirs[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                           {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
public:
    double knightProbability(int n, int k, int r, int c) {

        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, -1)));
        return dfs(n, k, r, c, dp);
    }

private:
    double dfs(int n, int k, int r, int c,
               vector<vector<vector<double>>>& dp) {

        if(k == 0) return 1;
        if(dp[k][r][c] >= 0.0) return dp[k][r][c];

        double res = 0.0;
        for(int d = 0; d < 8; d ++){
            int nr = r + dirs[d][0], nc = c + dirs[d][1];
            if(in_area(nr, nc, n))
                res += 0.125 * dfs(n, k - 1, nr, nc, dp);
        }
        return dp[k][r][c] = res;
    }

    bool in_area(int x, int y, int n){
        return 0 <= x && x < n && 0 <= y && y < n;
    }
};


int main() {

    cout << Solution().knightProbability(8, 30, 6, 4) << endl;

    return 0;
}
