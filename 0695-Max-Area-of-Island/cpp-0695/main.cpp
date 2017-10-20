/// Source : https://leetcode.com/problems/max-area-of-island/description/
/// Author : liuyubobobo
/// Time   : 2017-10-19

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// floodfill
// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
class Solution {

private:
    int d[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n, m;
    bool visited[50][50];

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        assert(n > 0);
        m = grid[0].size();

        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                visited[i][j] = false;

        int res = 0;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(!visited[i][j] && grid[i][j] == 1)
                    res = max(res, dfs(grid, i, j));

        return res;
    }

private:
    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int dfs(const vector<vector<int>>& grid, int x, int y){

        visited[x][y] = true;

        int res = 1;
        for(int i = 0 ; i < 4 ; i ++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == 1)
                res += dfs(grid, newx, newy);
        }

        return res;
    }
};

int main() {

    return 0;
}