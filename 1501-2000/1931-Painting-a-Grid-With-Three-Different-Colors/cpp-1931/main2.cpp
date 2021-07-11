/// Source : https://leetcode.com/problems/painting-a-grid-with-three-different-colors/
/// Author : liuyubobobo
/// Time   : 2021-07-10

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DP
/// Time Complexity: O((3^m)^2 * n)
/// Space Complexity: O(3^m)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int colorTheGrid(int m, int n) {

        int L = 1;
        for(int i = 0; i < m; i ++) L *= 3;

        set<int> okstate;
        for(int state = 0; state < L; state ++)
            if(ok(state, m))
                okstate.insert(state);

        vector<vector<int>> next(L, vector<int>());
        for(int state: okstate)
            get_next(m, state, 0, 0, next[state]);

        vector<int> dp(L, 0);
        for(int state: okstate) dp[state] = 1;
        for(int i = n - 2; i >= 0; i --){
            vector<int> tdp(L, 0);
            for(int state: okstate)
                for(int nextstate: next[state])
                    tdp[state] = (tdp[state] + dp[nextstate]) % MOD;
            dp = tdp;
        }

        int res = 0;
        for(int e: dp) res = (res + e) % MOD;
        return res;
    }

private:
    void get_next(int m, int state, int index, int next_state,
                  vector<int>& next){

        if(index == m){
            next.push_back(next_state);
            return;
        }

        for(int color = 0; color < 3; color ++)
            if(color != state % 3){
                if(index > 0 && color == next_state % 3)
                    continue;
                get_next(m, state / 3, index + 1, next_state * 3 + color, next);
            }
    }

    bool ok(int x, int len){

        vector<int> v(len);
        for(int i = 0; i < len; i ++){
            v[i] = x % 3, x /= 3;
            if(i && v[i] == v[i - 1]) return false;
        }
        return true;
    }
};


int main() {

    cout << Solution().colorTheGrid(1, 1) << endl;
    // 3

    cout << Solution().colorTheGrid(1, 2) << endl;
    // 6

    cout << Solution().colorTheGrid(5, 5) << endl;
    // 580986

    cout << Solution().colorTheGrid(2, 37) << endl;
    // 478020091

    cout << Solution().colorTheGrid(5, 1000) << endl;
    // 408208448

    return 0;
}
