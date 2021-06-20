/// Source : https://leetcode.com/problems/count-sub-islands/
/// Author : liuyubobobo
/// Time   : 2021-06-20

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    int R, C;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        R = grid1.size(), C = grid1[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid2[i][j] && !visited[i][j]){
                    bool ok = true;
                    dfs(grid2, i, j, visited, ok, grid1);
                    res += ok;
                }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& g, int x, int y,
             vector<vector<bool>>& visited, bool& ok,
             const vector<vector<int>>& g2){

        visited[x][y] = true;

        if(g2[x][y] == 0) ok = false;

        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && g[nx][ny] == 1 && !visited[nx][ny])
                dfs(g, nx, ny, visited, ok, g2);
        }
    }

    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    vector<vector<int>> g11 = {
            {1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}
    };
    vector<vector<int>> g12 = {
            {1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}
    };
    cout << Solution().countSubIslands(g11, g12) << endl;
    // 3

    vector<vector<int>> g21 = {
            {1,0,1,0,1},
            {1,1,1,1,1},
            {0,0,0,0,0},
            {1,1,1,1,1},
            {1,0,1,0,1}
    };
    vector<vector<int>> g22 = {
            {0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0}, {0,1,0,1,0},{1,0,0,0,1}
    };
    cout << Solution().countSubIslands(g21, g22) << endl;
    // 2

    return 0;
}
