/// Source : https://leetcode.com/problems/unique-paths-iii/
/// Author : liuyubobobo
/// Time   : 2019-01-21

/// Memory Search
/// Time Complexity: O(m * n * 2 ^ (m * n))
/// Space Complexity: O(m * n)
class Solution2 {

    private int m, n, end;
    private int d[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public int uniquePathsIII(int[][] grid) {

        m = grid.length;
        n = grid[0].length;
        int start = 0, state = 0;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                int pos = i * n + j;
                if(grid[i][j] == 1){
                    start = pos;
                    state += (1 << pos);
                }
                else if(grid[i][j] == 2){
                    end = pos;
                    grid[i][j] = 0;
                }
                else if(grid[i][j] == -1)
                    state += (1 << pos);
            }

        int[][] dp = new int[1 << (m * n)][m * n];
        for(int i = 0; i < (1 << (m * n)); i ++)
            for(int j = 0; j < m * n; j ++)
                dp[i][j] = -1;
        return dfs(grid, state, start, dp);
    }

    private int dfs(int[][] grid, int state, int pos, int[][] dp){

        if(pos == end)
            return state == (1 << m * n) - 1 ? 1 : 0;

        if(dp[state][pos] != -1)
            return dp[state][pos];

        int x = pos / n, y = pos % n, res = 0;
        for(int i = 0; i < 4; i ++){
            int nextx = x + d[i][0], nexty = y + d[i][1];
            int next = nextx * n + nexty;
            if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && (state & (1 << next)) == 0)
                res += dfs(grid, state | (1 << next), next, dp);
        }
        return dp[state][pos] = res;
    }
}