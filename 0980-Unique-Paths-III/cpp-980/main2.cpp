/// Source : https://leetcode.com/problems/unique-paths-iii/
/// Author : liuyubobobo
/// Time   : 2020-04-28

#include <iostream>
#include <vector>

using namespace std;


/// State Compression + Memory Search
/// Time Complexity: O(m * n * 2 ^ (m * n))
/// Space Complexity: O(m * n * 2 ^ (m * n))
class Solution {

private:
    int m, n, end;
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        m = grid.size(), n = grid[0].size();
        int start, state = 0;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                int pos = i * n + j;
                if(grid[i][j] == 1)
                    start = pos;
                else if(grid[i][j] == 2)
                    end = pos, grid[i][j] = 0;
                else if(grid[i][j] == -1)
                    state |= (1 << pos);
            }
        vector<vector<int>> dp((m * n), vector<int>(1 << (m * n), -1));
        return dfs(grid, state | (1 << start), start, dp);
    }

private:
    int dfs(vector<vector<int>>& grid, int state, int pos, vector<vector<int>>& dp){

        if(pos == end)
            return state == (1 << (m * n)) - 1 ? 1 : 0;
        if(dp[pos][state] != -1) return dp[pos][state];

        int x = pos / n, y = pos % n, res = 0;
        for(int i = 0; i < 4; i ++){
            int nextx = x + d[i][0], nexty = y + d[i][1];
            int next = nextx * n + nexty;
            if(in_area(nextx, nexty) && (state & (1 << next)) == 0){
                res += dfs(grid, state | (1 << next), next, dp);
            }
        }
        return dp[pos][state] = res;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
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

    vector<vector<int>> g3 = {
            {0,0,0,0,0},
            {0,2,1,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}
    };
    cout << Solution().uniquePathsIII(g3) << endl;
    // 8

    return 0;
}