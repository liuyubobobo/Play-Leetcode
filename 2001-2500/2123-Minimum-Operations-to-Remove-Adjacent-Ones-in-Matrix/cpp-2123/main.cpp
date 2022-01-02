#include <iostream>
#include <vector>

using namespace std;


class Solution {

private:
    int R, C;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumOperations(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(grid, i, j, visited);

                    vector<vector<bool>> visited2(R, vector<bool>(C, false));
                    int tres1 = solve(grid, visited, i, j, 1, visited2);

                    visited2.assign(R, vector<bool>(C, false));
                    int tres2 = solve(grid, visited, i, j, 0, visited2);
                    res += min(tres1, tres2);
                }
        return res;
    }

private:
    int solve(const vector<vector<int>>& grid, const vector<vector<bool>>& ok,
              int x, int y, int v, vector<vector<bool>>& visited){

        visited[x][y] = true;

        int res = 1 - v;
        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && ok[nx][ny] && !visited[nx][ny])
                res += solve(grid, ok, nx, ny, 1 - v, visited);
        }
        return res;
    }

    void dfs(const vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited){

        visited[x][y] = true;
        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny])
                dfs(grid, nx, ny, visited);
        }
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

//    vector<vector<int>> grid1 = {
//            {1, 1, 0}, {0, 1, 1}, {1, 1, 1}
//    };
//    cout << Solution().minimumOperations(grid1) << endl;
//    // 3

    vector<vector<int>> grid2 = {
            {0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1}, {0, 1, 0, 0, 1, 0}
    };
    cout << Solution().minimumOperations(grid2) << endl;
    // 3

    return 0;
}
