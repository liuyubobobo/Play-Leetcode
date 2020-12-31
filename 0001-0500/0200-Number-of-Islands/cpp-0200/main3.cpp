/// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : liuyubobobo
/// Time   : 2018-08-25

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// Floodfill - BFS
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution {

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();
        if(n == 0)
            return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int res = 0;
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0 ; j < n ; j ++)
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(grid, i, j, visited);
                    res ++;
                }
        return res;
    }

private:
    void bfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited){

        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visited[x][y] = true;
        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i ++){
                int newX = curx + d[i][0];
                int newY = cury + d[i][1];
                if(inArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1'){
                    q.push(make_pair(newX, newY));
                    visited[newX][newY] = true;
                }
            }
        }

        return;
    }

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    vector<vector<char>> grid1 = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    cout << Solution().numIslands(grid1) << endl;
    // 1

    // ---

    vector<vector<char>> grid2 = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    cout << Solution().numIslands(grid2) << endl;
    // 3

    return 0;
}