/// Source : https://leetcode.com/problems/count-fertile-pyramids-in-a-land/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {

        int res = solve(grid);
        reverse(grid.begin(), grid.end());
        res += solve(grid);

        return res;
    }

private:
    int solve(vector<vector<int>>& g){

        int R = g.size(), C = g[0].size();
        vector<vector<int>> dp(R, vector<int>(C, 0));

        int res = 0;
        for(int i = R - 2; i >= 0; i --)
            for(int j = 1; j + 1 < C; j ++){
                if(g[i][j] && g[i + 1][j - 1] && g[i + 1][j] && g[i + 1][j + 1])
                    dp[i][j] = 1 + min(min(dp[i + 1][j - 1], dp[i + 1][j]), dp[i + 1][j + 1]);
                res += dp[i][j];
            }
        return res;
    }
};

int main() {

    vector<vector<int>> grid1 = {{0, 1, 1, 0}, {1, 1, 1, 1}};
    cout << Solution().countPyramids(grid1) << endl;
    // 2

    vector<vector<int>> grid2 = {{1, 1, 1}, {1, 1, 1}};
    cout << Solution().countPyramids(grid2) << endl;
    // 2

    vector<vector<int>> grid3 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    cout << Solution().countPyramids(grid3) << endl;
    // 0

    vector<vector<int>> grid4 = {{1,1,1,1,0}, {1,1,1,1,1}, {1,1,1,1,1}, {0,1,0,0,1}};
    cout << Solution().countPyramids(grid4) << endl;
    // 13

    return 0;
}
