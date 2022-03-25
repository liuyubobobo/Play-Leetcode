/// Source : https://leetcode.com/problems/detect-cycles-in-2d-grid/
/// Author : liuyubobobo
/// Time   : 2022-03-25

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    bool containsCycle(vector<vector<char>>& grid) {

        R = grid.size(), C = grid[0].size();

        vector<vector<int>> visited(R, vector<int>(C, -1));
        int tag = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(visited[i][j] == -1 && dfs(grid, i, j, -1, -1, tag ++, visited))
                    return true;
        return false;
    }

private:
    bool dfs(const vector<vector<char>>& grid, int cx, int cy, int px, int py,
             int tag, vector<vector<int>>& visited){

        visited[cx][cy] = tag;

        for(int d = 0; d < 4; d ++){
            int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
            if(!in_area(nx, ny)) continue;
            if(grid[nx][ny] != grid[cx][cy]) continue;
            if(nx == px && ny == py) continue;

            if(visited[nx][ny] == tag) return true;
            if(dfs(grid, nx, ny, cx, cy, tag, visited)) return true;
        }
        return false;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
