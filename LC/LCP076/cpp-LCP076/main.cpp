/// Source : https://leetcode.cn/problems/1ybDKD/
/// Author : liuyubobobo
/// Time   : 2023-04-23

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


/// State Compression DP
/// Time Complexity: O(3^(min(R, C))^2 * max(R, C))
/// Space Complexity: O(3^(min(R, C))^3)

int pow3[6];
int new_states[243][243][243][2];
long long dp[30][243][243];

class Solution {

private:
    int R, C;


public:
    long long getSchemeCount(int n, int m, vector<string>& chessboard) {

        pow3[0] = 1;
        for(int i = 1; i <= 5; i ++) pow3[i] = pow3[i - 1] * 3ll;

        memset(new_states, -1, sizeof(new_states));

        R = chessboard.size(), C = chessboard[0].size();
        if(C > R) chessboard = rotate(chessboard), swap(R, C);

        memset(dp, -1, sizeof(dp));
        return dfs(chessboard, 0, 0, 0);
    }

private:
    long long dfs(const vector<string>& chessboard, int index, int state0, int state1){

        if(index == R) return 1;
        if(dp[index][state0][state1] != -1) return dp[index][state0][state1];

        vector<int> ok_states;
        get_ok_states(chessboard[index], state0, state1, 0, 0, 0, ok_states);

        long long res = 0;
        for(int state: ok_states){

            if(new_states[state0][state1][state][0] == -1){
                vector<int> states = {state0, state1, state};
                get_new_state(states, new_states[state0][state1][state]);
            }

            res += dfs(chessboard, index + 1, new_states[state0][state1][state][0], new_states[state0][state1][state][1]);
        }
        return dp[index][state0][state1] = res;
    }

    void get_new_state(const vector<int>& states, int res[2]){

        res[0] = res[1] = 0;
        for(int j = 0; j < 5; j ++){
            int write_pos = 1;
            for(int i = 2; i >= 0 && write_pos >= 0; i --){
                int val = states[i] / pow3[5 - 1 - j] % 3;
                if(val) res[write_pos --] += val * pow3[5 - 1 - j];
            }
        }
    }

    void get_ok_states(const string& s, int state0, int state1, int index, int state,
                       int pre, vector<int>& ok_states){

        if(index == C){
            ok_states.push_back(state);
            return;
        }

        int l, r;
        if(s[index] != '?') l = r = (s[index] == '.' ? 0 : (s[index] == 'R' ? 1 : 2));
        else l = 0, r = 2;

        for(int val = l; val <= r; val ++){
            int val0 = state0 / pow3[C - 1 - index] % 3, val1 = state1 / pow3[C - 1 - index] % 3;
            if(val0 && val1 && val && val != val0) continue;
            if(pre / 3 % 3 && val && pre / 3 % 3 != val) continue;

            if(val) pre = pre * 3 + val;
            get_ok_states(s, state0, state1, index + 1, state * 3 + val, pre, ok_states);
            if(val) pre /= 3;
        }
        return;
    }

    vector<string> rotate(const vector<string>& A){

        int r = A.size(), c = A[0].size();

        vector<string> B(c, string(r, ' '));
        for(int i = 0; i < r; i ++)
            for(int j = 0; j < c; j ++)
                B[j][R - 1 - i] = A[i][j];
        return B;
    }
};


int main() {

    vector<string> chessboard1 = {"..R","..B","?R?"};
    cout << Solution().getSchemeCount(3, 3, chessboard1) << '\n';
    // 5

    vector<string> chessboard2 = {"?R?","B?B","?R?"};
    cout << Solution().getSchemeCount(3, 3, chessboard2) << '\n';
    // 105

    vector<string> chessboard3 = {"?B?B","R?.?"};
    cout << Solution().getSchemeCount(2, 4, chessboard3) << '\n';
    // 42

    vector<string> chessboard4 = {"????","???.","????","??R?"};
    cout << Solution().getSchemeCount(4, 4, chessboard4) << '\n';
    // 322765

    vector<string> chessboard5 = {
            "??.B??","??????","??B???","??????","???.?."
    };
    cout << Solution().getSchemeCount(5, 6, chessboard5) << '\n';

    return 0;
}
