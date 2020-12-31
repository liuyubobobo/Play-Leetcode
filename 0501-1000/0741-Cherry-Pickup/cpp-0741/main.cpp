/// Source : https://leetcode.com/problems/cherry-pickup/description/
/// Author : liuyubobobo
/// Time   : 2017-12-02

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
///
/// Think it as two pass from top-left to bottom-down problem
/// dp[x1][x2][step]: the x of first route is x1;
///                   the x of second route is x2;
///                   the length of the two route is step;
/// We can calculate y1 and y2 by step - x1 and step - x2
///
/// Time Complexity: O(n*n*(2*n-1))
/// Space Complexity: O(n*n*(2*n-1))
class Solution {

private:
    int n;
    int d[4][2] = {{1, 0}, {0, 1}};

public:
    int cherryPickup(vector<vector<int>>& grid) {

        assert(grid.size() > 0);
        n = grid.size();

        assert(grid[0].size() == n);

        vector<vector<vector<int>>> dp(
                n, vector<vector<int>>(
                        n, vector<int>( 2 * n -1, INT_MIN)));
        int res = findResult(grid, 0, 0, 0, dp);
        return res == -1 ? 0 : res;
    }

private:
    int findResult(const vector<vector<int>>& grid,
                   int x1, int x2, int step,
                   vector<vector<vector<int>>>& dp){

        if(dp[x1][x2][step] != INT_MIN)
            return dp[x1][x2][step];

        if(step == 2* n - 2) {
            assert(x1 == n - 1 && x2 == n - 1);
            return dp[x1][x2][step] = (grid[n-1][n-1] == -1 ? -1 : grid[n-1][n-1]);
        }

        int ret = -1;
        int y1 = step - x1;
        int y2 = step - x2;
        int res = grid[x1][y1];
        if(x1 != x2 || y1 != y2)
            res += grid[x2][y2];

        for(int d1 = 0 ; d1 < 2 ; d1 ++){
            int newX1 = x1 + d[d1][0];
            int newY1 = y1 + d[d1][1];
            if(inArea(newX1, newY1) && grid[newX1][newY1] != -1)
                for(int d2 = 0 ; d2 < 2 ; d2 ++){
                    int newX2 = x2 + d[d2][0];
                    int newY2 = y2 + d[d2][1];
                    if(inArea(newX2, newY2) && grid[newX2][newY2] != -1){
                        int next_res = findResult(grid, newX1, newX2, step + 1, dp);
                        if(next_res != -1)
                            ret = max(ret, res + next_res);
                    }
                }
        }

//        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " : " << ret << endl;
        return dp[x1][x2][step] = ret;
    }

    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    }
};

int main() {

    vector<vector<int>> grid0 = {{1, 1},
                                 {1, 1}};
    cout << Solution().cherryPickup(grid0) << endl;
    // 4

    // ---

    vector<vector<int>> grid1 = {{0, 1, -1},
                                 {1, 0, -1},
                                 {1, 1,  1}};
    cout << Solution().cherryPickup(grid1) << endl;
    // 5

    // ---

    vector<vector<int>> grid2 = {{1, 1, -1},
                                 {1, -1, 1},
                                 {-1, 1,  1}};
    cout << Solution().cherryPickup(grid2) << endl;
    // 0

    return 0;
}