/// Source : https://leetcode.com/problems/maximize-grid-happiness/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memory Search
/// Row by row
/// Time Complexity: O(R * in * ex * (1 << C) * (1 << C))
/// Space Complexity: O(R * in * ex * (1 << C))
class Solution {

private:
    int statemax;
    vector<vector<int>> score, fix;
    vector<int> in_cnt, ex_cnt;

public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {

        statemax = 1;
        for(int i = 0; i < n; i ++) statemax *= 3;

        score = vector<vector<int>>(statemax, vector<int>(statemax));
        fix = vector<vector<int>>(statemax, vector<int>(statemax));;
        for(int state1 = 0; state1 < statemax; state1 ++){
            vector<int> v1 = get_state_v(state1, n);
            for(int state2 = 0; state2 < statemax; state2 ++){
                vector<int> v2 = get_state_v(state2, n);
                score[state1][state2] = get_score(v1, v2);
                fix[state1][state2] = get_fix(v1, v2);
            }
        }

        in_cnt = vector<int>(statemax, 0);
        ex_cnt = vector<int>(statemax, 0);
        for(int state = 0; state < statemax; state ++)
            get_in_and_ex(state);

        int dp[6][7][7][729];
        memset(dp, -1, sizeof(dp));
        return dfs(m, introvertsCount, extrovertsCount, 0, dp);
    }

private:
    int dfs(int leftrow, int in, int ex, int last, int dp[6][7][7][729]){

        if(leftrow == 0) return 0;
        if(dp[leftrow][in][ex][last] != -1) return dp[leftrow][in][ex][last];

        int res = 0;
        for(int state = 0; state < statemax; state ++)
            if(in >= in_cnt[state] && ex >= ex_cnt[state])
                res = max(res, score[state][last] + fix[last][state] + dfs(leftrow - 1, in - in_cnt[state], ex - ex_cnt[state], state, dp));
        return dp[leftrow][in][ex][last] = res;
    }

    vector<int> get_state_v(int state, int col){

        vector<int> res(col, 0);
        for(int i = 0; i < col; i ++)
            res[i] = state % 3, state /= 3;
        return res;
    }

    int get_score(const vector<int>& curv, const vector<int>& lastv){

        vector<int> v(curv.size(), 0);
        for(int i = 0; i < v.size(); i ++)
            if(curv[i] == 1){
                v[i] = 120;
                if(i > 0 && curv[i - 1]) v[i] -= 30;
                if(lastv[i]) v[i] -= 30;
                if(i + 1 < v.size() && curv[i + 1]) v[i] -= 30;
            }
            else if(curv[i] == 2){
                v[i] = 40;
                if(i > 0 && curv[i - 1]) v[i] += 20;
                if(lastv[i]) v[i] += 20;
                if(i + 1 < v.size() && curv[i + 1]) v[i] += 20;
            }
        return accumulate(v.begin(), v.end(), 0);
    }

    int get_fix(const vector<int>& curv, const vector<int>& lastv){

        int res = 0;
        for(int i = 0; i < curv.size(); i ++)
            if(curv[i] == 1 && lastv[i]) res -= 30;
            else if(curv[i] == 2 && lastv[i]) res += 20;
        return res;
    }

    void get_in_and_ex(int state){

        int x = state;
        while(x){
            if(x % 3 == 1) in_cnt[state] ++;
            else if(x % 3 == 2) ex_cnt[state] ++;
            x /= 3;
        }
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
