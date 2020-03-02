/// Source : https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
/// Author : liuyubobobo
/// Time   : 2020-03-01

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Compelxity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    const int dirs[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    int m, n;

public:
    int minCost(vector<vector<int>>& grid) {

        for(vector<int>& row: grid)
            for(int& e: row) if(e == 4) e = 0;

        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        queue<int> q;
        dfs(grid, 0, 0, 0, dp, q);
        while(!q.empty()){
            int x = q.front() / n, y = q.front() % n;
            q.pop();

            for(int d = 0; d < 4; d ++)
                if(d != grid[x][y]){
                    int nextx = x + dirs[d][0], nexty = y + dirs[d][1];
                    if(in_area(nextx, nexty) && dp[nextx][nexty] == -1)
                        dfs(grid, nextx, nexty, dp[x][y] + 1, dp, q);
                }
        }
        return dp[m - 1][n - 1];
    }

private:
    void dfs(const vector<vector<int>>& grid, int x, int y, int cost,
            vector<vector<int>>& dp, queue<int>& q){

        if(dp[x][y] != -1) return;
        dp[x][y] = cost;
        q.push(x * n + y);

        if(in_area(x + dirs[grid[x][y]][0], y + dirs[grid[x][y]][1]))
            dfs(grid, x + dirs[grid[x][y]][0], y + dirs[grid[x][y]][1], cost, dp, q);
        return;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    vector<vector<int>> grid1 = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    cout << Solution().minCost(grid1) << endl;
    // 3

    vector<vector<int>> grid2 = {{1,1,3},{3,2,2},{1,1,4}};
    cout << Solution().minCost(grid2) << endl;
    // 0

    // [[3,4,3],[2,2,2],[2,1,1],[4,3,2],[2,1,4],[2,4,1],[3,3,3],[1,4,2],[2,2,1],[2,1,1],[3,3,1],[4,1,4],[2,1,4],[3,2,2],[3,3,1],[4,4,1],[1,2,2],[1,1,1],[1,3,4],[1,2,1],[2,2,4],[2,1,3],[1,2,1],[4,3,2],[3,3,4],[2,2,1],[3,4,3],[4,2,3],[4,4,4]]
    // 18

    return 0;
}
