/// Source : https://leetcode.com/problems/maximize-grid-happiness/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memory Search
/// One by one
/// Time Complexity: O(R * C * in * ex * (1 << C))
/// Space Complexity: O(R * C * in * ex * (1 << C))
class Solution {

private:
    int statemax = 1, mod, R, C;

public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {

        R = m, C = n;
        for(int i = 0; i < n; i ++) statemax *= 3;
        mod = statemax / 3;

        int dp[5][5][7][7][729];
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, introvertsCount, extrovertsCount, 0, dp);
    }

private:
    int dfs(int x, int y, int in, int ex, int last, int dp[5][5][7][7][729]){

        if(x == R) return 0;
        if(y == C) return dfs(x + 1, 0, in, ex, last, dp);
        if(dp[x][y][in][ex][last] != -1) return dp[x][y][in][ex][last];

        int res = dfs(x, y + 1, in, ex, last % mod * 3, dp);

        if(in) {
            int t1 = 120, up = last / mod, left = last % 3;
            if (x - 1 >= 0 && up) {
                t1 -= 30;
                t1 += up == 1 ? -30 : 20;
            }
            if (y - 1 >= 0 && left) {
                t1 -= 30;
                t1 += left == 1 ? -30 : 20;
            }
            res = max(res, t1 + dfs(x, y + 1, in - 1, ex, last % mod * 3 + 1, dp));
        }

        if(ex) {
            int t2 = 40, up = last / mod, left = last % 3;;
            if (x - 1 >= 0 && up) {
                t2 += 20;
                t2 += up == 1 ? -30 : 20;
            }
            if (y - 1 >= 0 && left) {
                t2 += 20;
                t2 += left == 1 ? -30 : 20;
            }
            res = max(res, t2 + dfs(x, y + 1, in, ex - 1, last % mod * 3 + 2, dp));
        }
        return dp[x][y][in][ex][last] = res;
    }
};


int main() {

    cout << Solution().getMaxGridHappiness(2, 3, 1, 2) << endl;
    // 240

    cout << Solution().getMaxGridHappiness(3, 1, 2, 1) << endl;
    // 260

    cout << Solution().getMaxGridHappiness(2, 2, 4, 0) << endl;
    // 240

    cout << Solution().getMaxGridHappiness(3, 1, 1, 3) << endl;
    // 230

    return 0;
}
