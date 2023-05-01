/// Source : https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int R, C;

public:
    int findMaxFish(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(grid[i][j] == 0 || visited[i][j]) continue;
                res = max(res, dfs(grid, i, j, visited));
            }
        return res;
    }

private:
    int dfs(const vector<vector<int>>& grid, int cx, int cy, vector<vector<bool>>& visited){

        int res = grid[cx][cy];
        visited[cx][cy] = true;
        for(int d = 0; d < 4; d ++){
            int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
            if(in_area(nx, ny) && grid[nx][ny] && !visited[nx][ny])
                res += dfs(grid, nx, ny, visited);
        }
        return res;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
