/// Source : https://leetcode.com/problems/regions-cut-by-slashes/
/// Author : liuyubobobo
/// Time   : 2018-12-15

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(4 * m * n)
/// Space Complexity: O(4 * m * n)
class Solution {

private:
    const int d[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int m, n;

public:
    int regionsBySlashes(vector<string>& grid) {

        m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> visited(m,
                vector<vector<bool>>(n, vector<bool>(4, false)));

        int res = 0;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                for(int k = 0; k < 4; k ++)
                    if(!visited[i][j][k])
                        res ++, dfs(grid, i, j, k, visited);
        return res;
    }

private:
    void dfs(const vector<string>& grid, int r, int c, int k,
             vector<vector<vector<bool>>>& visited){

        visited[r][c][k] = true;
        if(grid[r][c] == '/'){
            if(k < 2){
                if(!visited[r][c][1 - k]) dfs(grid, r, c, 1 - k, visited);
            }
            else{
                if(!visited[r][c][5 - k]) dfs(grid, r, c, 5 - k, visited);
            }
        }
        else if(grid[r][c] == '\\'){
            if(!visited[r][c][3 - k]) dfs(grid, r, c, 3 - k, visited);
        }
        else{
            for(int kk = 0; kk < 4; kk ++)
                if(!visited[r][c][kk])
                    dfs(grid, r, c, kk, visited);
        }

        int nextr = r + d[k][0], nextc = c + d[k][1];
        if(in_area(nextr, nextc)){
            if(k % 2){
                if(!visited[nextr][nextc][4 - k]) dfs(grid, nextr, nextc, 4 - k, visited);
            }
            else{
                if(!visited[nextr][nextc][2 - k]) dfs(grid, nextr, nextc, 2 - k, visited);
            }
        }
    }

    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    return 0;
}