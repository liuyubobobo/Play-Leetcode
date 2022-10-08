/// Source : https://leetcode-cn.com/problems/YesdPw/
/// Author : liuyubobobo
/// Time   : 2021-06-19

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// DFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    int largestArea(vector<string>& grid) {

        R = grid.size(), C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(!visited[i][j]){
                    bool isOK = true;
                    int area = dfs(grid, grid[i][j], i, j, visited, isOK);
                    if(isOK) res = max(res, area);
                }
        return res;
    }

private:
    int dfs(const vector<string>& g, char c, int x, int y,
            vector<vector<bool>>& visited, bool& isOK){

        visited[x][y] = true;
        int res = 1;
        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(!in_area(nx, ny) || g[nx][ny] == '0'){
                isOK = false;
                continue;
            }

            if(g[nx][ny] == c && !visited[nx][ny])
                res += dfs(g, c, nx, ny, visited, isOK);
        }
        return res;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    vector<string> g1 = {"110","231","221"};
    cout << Solution().largestArea(g1) << endl;
    // 1

    vector<string> g2 = {"11111100000","21243101111","21224101221","11111101111"};
    cout << Solution().largestArea(g2) << endl;
    // 3

    return 0;
}
