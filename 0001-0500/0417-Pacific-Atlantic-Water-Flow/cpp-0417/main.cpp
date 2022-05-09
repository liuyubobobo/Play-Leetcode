/// Source : https://leetcode.com/problems/pacific-atlantic-water-flow/
/// Author : liuyubobobo
/// Time   : 2022-05-09

#include <iostream>
#include <vector>

using namespace std;


/// DFS from outside to inside
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int R, C;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        R = heights.size(), C = heights[0].size();

        vector<vector<bool>> pacific(R, vector<bool>(C, false));
        for(int j = 0; j < C; j ++)
            if(!pacific[0][j]) dfs(heights, 0, j, pacific);
        for(int i = 0; i < R; i ++)
            if(!pacific[i][0]) dfs(heights, i, 0, pacific);

        vector<vector<bool>> atlantic(R, vector<bool>(C, false));
        for(int i = 0; i < R; i ++)
            if(!atlantic[i][C - 1]) dfs(heights, i, C - 1, atlantic);
        for(int j = 0; j < C; j ++) dfs(heights, R - 1, j, atlantic);

        vector<vector<int>> res;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i, j});
        return res;
    }

private:
    void dfs(const vector<vector<int>>& H, int x, int y, vector<vector<bool>>& visited){

        visited[x][y] = true;
        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && !visited[nx][ny] && H[x][y] <= H[nx][ny])
                dfs(H, nx, ny, visited);
        }
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
