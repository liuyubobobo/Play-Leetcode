/// Source : https://leetcode.com/problems/maximize-grid-happiness/
/// Author : liuyubobobo
/// Time   : 2020-11-14

/// Memory Search
/// One by one
/// Time Complexity: O(R * C * in * ex * (1 << C))
/// Space Complexity: O(R * C * in * ex * (1 << C))
class Solution2 {

    private int statemax = 1, mod = 0, R = 0, C = 0;
    private int[][][][][] dp;

    public int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {

        R = m;
        C = n;
        for(int i = 0; i < n; i ++) statemax *= 3;
        mod = statemax / 3;

        dp = new int[m][n][introvertsCount + 1][extrovertsCount + 1][statemax];
        return dfs(0, 0, introvertsCount, extrovertsCount, 0);
    }

    private int dfs(int x, int y, int in, int ex, int last){

        if(x == R) return 0;
        if(y == C) return dfs(x + 1, 0, in, ex, last);
        if(dp[x][y][in][ex][last] != 0) return dp[x][y][in][ex][last];

        int res = dfs(x, y + 1, in, ex, last % mod * 3);

        if(in != 0) {
            int t1 = 120, up = last / mod, left = last % 3;
            if (x - 1 >= 0 && up != 0) {
                t1 -= 30;
                t1 += up == 1 ? -30 : 20;
            }
            if (y - 1 >= 0 && left != 0) {
                t1 -= 30;
                t1 += left == 1 ? -30 : 20;
            }
            res = Math.max(res, t1 + dfs(x, y + 1, in - 1, ex, last % mod * 3 + 1));
        }

        if(ex != 0) {
            int t2 = 40, up = last / mod, left = last % 3;;
            if (x - 1 >= 0 && up != 0) {
                t2 += 20;
                t2 += up == 1 ? -30 : 20;
            }
            if (y - 1 >= 0 && left != 0) {
                t2 += 20;
                t2 += left == 1 ? -30 : 20;
            }
            res = Math.max(res, t2 + dfs(x, y + 1, in, ex - 1, last % mod * 3 + 2));
        }
        return dp[x][y][in][ex][last] = res;
    }
}