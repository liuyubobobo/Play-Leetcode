/// Source : https://leetcode.com/problems/maximize-grid-happiness/
/// Author : liuyubobobo
/// Time   : 2020-11-14

/// Memory Search
/// Row by row
/// Time Complexity: O(R * in * ex * (1 << C) * (1 << C))
/// Space Complexity: O(R * in * ex * (1 << C))
class Solution {

    private int statemax = 1;
    private int[][][][] dp;
    private int[][] score, fix;
    private int[] inCnt, exCnt;

    public int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {

        for(int i = 0; i < n; i ++)
            statemax *= 3;

        // 预处理 score 和 fix
        score = new int[statemax][statemax];
        fix = new int[statemax][statemax];
        for(int state1 = 0; state1 < statemax; state1 ++){

            int[] v1 = getStateArray(state1, n);
            for(int state2 = 0; state2 < statemax; state2 ++){

                int[] v2 = getStateArray(state2, n);
                score[state1][state2] = getScore(v1, v2, n);
                fix[state1][state2] = getFix(v1, v2, n);
            }
        }

        // 预处理每个状态的内向人数和外向人数
        inCnt = new int[statemax];
        exCnt = new int[statemax];
        for(int state = 0; state < statemax; state ++)
            getInAndEx(state);

        dp = new int[m + 1][introvertsCount + 1][extrovertsCount + 1][statemax];
        return dfs(m, introvertsCount, extrovertsCount, 0);
    }

    // 记忆化搜索
    private int dfs(int leftrow, int in, int ex, int last){

        if(leftrow == 0) return 0;
        if(in == 0 && ex == 0) return 0;

        if(dp[leftrow][in][ex][last] != 0)
            return dp[leftrow][in][ex][last];

        int res = 0;
        for(int state = 0; state < statemax; state ++){
            // in 和 ex 人数够用，可以安排，则进行状态转移
            if(in >= inCnt[state] && ex >= exCnt[state])
                res = Math.max(res, score[state][last] + fix[last][state] + dfs(leftrow - 1, in - inCnt[state], ex - exCnt[state], state));
        }
        return dp[leftrow][in][ex][last] = res;
    }

    // 下面都是各种预处理需要的辅助函数
    private int[] getStateArray(int state, int col){

        int[] res = new int[col];
        for(int i = 0; i < col; i ++){
            res[i] = state % 3;
            state /= 3;
        }
        return res;
    }

    private int getScore(int[] curv, int[] lastv, int col){

        int res = 0, t = 0;
        for(int i = 0; i < col; i ++){
            t = 0;
            if(curv[i] == 1){
                t = 120;
                if(i > 0 && curv[i - 1] != 0) t -= 30;
                if(lastv[i] != 0) t -= 30;
                if(i + 1 < col && curv[i + 1] != 0) t -= 30;
            }
            else if(curv[i] == 2){
                t = 40;
                if(i > 0 && curv[i - 1] != 0) t += 20;
                if(lastv[i] != 0) t += 20;
                if(i + 1 < col && curv[i + 1] != 0) t += 20;
            }
            res += t;
        }
        return res;
    }

    private int getFix(int[] curv, int[] lastv, int col){

        int res = 0;
        for(int i = 0; i < col; i ++)
            if(curv[i] == 1 && lastv[i] != 0) res -= 30;
            else if(curv[i] == 2 && lastv[i] != 0) res += 20;
        return res;
    }

    private void getInAndEx(int state){

        int in = 0, ex = 0, x = state;
        while(x != 0){
            if(x % 3 == 1) inCnt[state] ++;
            else if(x % 3 == 2) exCnt[state] ++;
            x /= 3;
        }
    }
}