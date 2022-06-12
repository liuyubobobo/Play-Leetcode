/// Source : https://leetcode.com/problems/minimum-path-cost-in-a-grid/
/// Author : liuyubobobo
/// Time   : 2022-06-11

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// DP
/// Time Complexity: O(n * m * m)
/// Space Compelxity: O(n * m)
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {

        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> dp(R, vector<int>(C, INT_MAX));
        for(int j = 0; j < C; j ++) dp[0][j] = grid[0][j];

        for(int i = 0; i + 1 < R; i ++)
            for(int j = 0; j < C; j ++){
                for(int k = 0; k < C; k ++)
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + moveCost[grid[i][j]][k] + grid[i + 1][k]);
            }
        return *min_element(dp[R - 1].begin(), dp[R - 1].end());
    }
};


int main() {

    return 0;
}
