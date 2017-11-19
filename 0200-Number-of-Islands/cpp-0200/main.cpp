/// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Floodfill
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution {

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    vector<vector<bool>> visited;

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(vector<vector<char>>& grid, int x, int y){

        //assert(inArea(x,y));
        visited[x][y] = true;
        for(int i = 0; i < 4; i ++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1')
                dfs(grid, newx, newy);
        }

        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();
        if(n == 0)
            return 0;

        for(int i = 0 ; i < m ; i ++)
            visited.push_back(vector<bool>(n, false));

        int res = 0;
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0 ; j < n ; j ++)
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, i, j);
                    res ++;
                }
        return res;
    }
};

int main() {

    char g1[4][5] = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    vector<vector<char>> grid1;
    for(int i = 0 ; i < 4 ; i ++)
        grid1.push_back( vector<char>(g1[i], g1[i] + sizeof( g1[i])/sizeof(char)));

    cout << Solution().numIslands(grid1) << endl;
    // 1

    // ---

    char g2[4][5] = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    vector<vector<char>> grid2;
    for(int i = 0 ; i < 4 ; i ++)
        grid2.push_back(vector<char>(g2[i], g2[i] + sizeof( g2[i])/sizeof(char)));

    cout << Solution().numIslands(grid2) << endl;
    // 2

    return 0;
}