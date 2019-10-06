/// Source : https://leetcode.com/problems/path-with-maximum-gold/
/// Author : liuyubobobo
/// Time   : 2019-10-05

#include <iostream>
#include <vector>

using namespace std;


/// Backtrcking
/// Time Complexity: O(2^(m*n))
/// Space Complexity: O(m*n)
class Solution {

private:
    int R, C;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int getMaximumGold(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();
//        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j])
                    res = max(res, dfs(grid, i, j));
        return res;
    }

private:
    int dfs(vector<vector<int>>& grid, int x, int y){

        int res = grid[x][y];
        int o = grid[x][y];
        grid[x][y] = 0;
        for(int d = 0; d < 4; d ++){
            int nextx = x + dirs[d][0], nexty = y + dirs[d][1];
            if(nextx >= 0 && nextx < R && nexty >= 0 && nexty < C && grid[nextx][nexty])
                res = max(res, o + dfs(grid, nextx, nexty));
        }
        grid[x][y] = o;
        return res;
    }
};


int main() {

    vector<vector<int>> grid1 = {{0,6,0},{5,8,7},{0,9,0}};
    cout << Solution().getMaximumGold(grid1) << endl;
    // 24

    vector<vector<int>> grid2 = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    cout << Solution().getMaximumGold(grid2) << endl;
    // 28

    return 0;
}