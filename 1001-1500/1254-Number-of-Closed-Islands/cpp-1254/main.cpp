/// Source : https://leetcode.com/problems/number-of-closed-islands/description/
/// Author : liuyubobobo
/// Time   : 2023-04-06

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    int R, C;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int closedIsland(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(visited[i][j] || grid[i][j] == 1) continue;
                res += !dfs(grid, i, j, visited);
            }
        return res;
    }

private:
    bool dfs(const vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited){

        bool ret = false;
        visited[x][y] = true;

        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 0)
                ret |= dfs(grid, nx, ny, visited);
            else if(!in_area(nx, ny))
                ret = true;
        }
        return ret;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};

int main() {

    return 0;
}
