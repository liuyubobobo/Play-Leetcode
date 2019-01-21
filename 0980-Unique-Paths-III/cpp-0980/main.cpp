/// Source : https://leetcode.com/problems/unique-paths-iii/
/// Author : liuyubobobo
/// Time   : 2019-01-21

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(4 ^ (m * n))
/// Space Complexity: O(m * n)
class Solution {

private:
    int m, n, end;
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        int start, todo = 0;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                int pos = i * n + j;
                if(grid[i][j] == 1)
                    start = pos;
                else if(grid[i][j] == 2)
                    end = pos, grid[i][j] = 0, todo ++;
                else if(grid[i][j] == 0)
                    todo ++;
            }
        return dfs(grid, start, todo);
    }

private:
    int dfs(vector<vector<int>>& grid, int pos, int todo){

        if(pos == end)
            return !todo;

        int x = pos / n, y = pos % n, res = 0;
        for(int i = 0; i < 4; i ++){
            int nextx = x + d[i][0], nexty = y + d[i][1];
            if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && grid[nextx][nexty] == 0){
                grid[nextx][nexty] = 1;
                res += dfs(grid, nextx * n + nexty, todo - 1);
                grid[nextx][nexty] = 0;
            }
        }
        return res;
    }
};


int main() {

    vector<vector<int>> g0 = {
            {1,0},
            {0,0},
            {0,2}
    };
    cout << Solution().uniquePathsIII(g0) << endl;
    // 1

    vector<vector<int>> g1 = {
            {1,0,0,0},
            {0,0,0,0},
            {0,0,2,-1}
    };
    cout << Solution().uniquePathsIII(g1) << endl;
    // 2

    vector<vector<int>> g2 = {
            {1,0,0,0},
            {0,0,0,0},
            {0,0,0,2}
    };
    cout << Solution().uniquePathsIII(g2) << endl;
    // 4

    return 0;
}