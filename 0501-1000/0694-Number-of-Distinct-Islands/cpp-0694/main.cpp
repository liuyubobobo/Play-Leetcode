/// Source : https://leetcode.com/problems/number-of-distinct-islands/description/
/// Author : liuyubobobo
/// Time   : 2017-10-19

#include <iostream>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

/// floodfill
/// Time Complexity: O(n*m*n*m)
/// Space Complexity: O(n*m)
class Solution {

private:
    int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int n, m;
    set<vector<vector<int>>> islands;
    int tag[50][50];

public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        assert(n > 0);
        m = grid[0].size();

        islands.clear();

        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                tag[i][j] = 0;

        // DFS
        int index = 1;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(tag[i][j] == 0 && grid[i][j] == 1){
                    dfs(grid, i, j, index);
                    islands.insert(getShape(grid, index));
                    index ++;
                }

        return islands.size();
    }

private:
    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(const vector<vector<int>>& grid, int x, int y, int index){

        tag[x][y] = index;

        for(int i = 0 ; i < 4 ; i ++){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx, newy) && tag[newx][newy] == 0 && grid[newx][newy] == 1)
                dfs(grid, newx, newy, index);
        }
    }

    vector<vector<int>> getShape(const vector<vector<int>>& grid, int index){

        int minx = n, miny = m, maxx = -1, maxy = -1;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(tag[i][j] == index){
                    minx = min(minx, i);
                    miny = min(miny, j);
                    maxx = max(maxx, i);
                    maxy = max(maxy, j);
                }

        vector<vector<int>> res(maxx-minx+1, vector<int>(maxy-miny+1, 0));
        for(int i = minx; i <= maxx ; i ++)
            for(int j = miny; j <= maxy; j ++)
                if(tag[i][j] == index)
                    res[i-minx][j-miny] = 1;

        return res;
    }
};

vector<vector<int>> getMapVec(string grid_map[], int n, int m){

    vector<vector<int>> res(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < grid_map[i].size() ; j ++)
            if(grid_map[i][j] == '1')
                res[i][j] = 1;
    return res;
}

int main() {

    int n1 = 4, m1 = 5;
    string grid_map1[] = {
            "11000",
            "11000",
            "00011",
            "00011",
    };
    vector<vector<int>> grid_map_vec1 = getMapVec(grid_map1, n1, m1);
    cout << Solution().numDistinctIslands(grid_map_vec1) << endl;

    int n2 = 4, m2 = 5;
    string grid_map2[] = {
            "11011",
            "10000",
            "00001",
            "11011",
    };
    vector<vector<int>> grid_map_vec2 = getMapVec(grid_map2, n2, m2);
    cout << Solution().numDistinctIslands(grid_map_vec2) << endl;

    return 0;
}