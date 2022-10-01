/// Source : https://leetcode-cn.com/problems/Y1VbOX/
/// Author : liuyubobobo
/// Time   : 2021-09-10

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Memoization
/// Time Complexity: O(20^4 * 2^4)
/// Space Complexity: O(20^4)
class Solution {
public:
    int trafficCommand(vector<string>& directions) {

        vector<vector<vector<vector<int>>>> dp(21, vector<vector<vector<int>>>(21, vector<vector<int>>(21, vector<int>(21, -1))));
        return dfs(directions, 0, 0, 0, 0, dp);
    }

private:
    int dfs(const vector<string>& directions, int a, int b, int c, int d,
            vector<vector<vector<vector<int>>>>& dp){

        if(a == directions[0].size() && b == directions[1].size() && c == directions[2].size() && d == directions[3].size())
            return 0;
        if(dp[a][b][c][d] != -1) return dp[a][b][c][d];

        int res = INT_MAX;
        for(int state = 1; state < 16; state ++){

            if((state & (1 << 0)) && a == directions[0].size()) continue;
            if((state & (1 << 1)) && b == directions[1].size()) continue;
            if((state & (1 << 2)) && c == directions[2].size()) continue;
            if((state & (1 << 3)) && d == directions[3].size()) continue;

            if(ok(state & (1 << 0) ? directions[0][a] : ' ',
                  state & (1 << 1) ? directions[1][b] : ' ',
                  state & (1 << 2) ? directions[2][c] : ' ',
                  state & (1 << 3) ? directions[3][d] : ' '))
                res = min(res, 1 + dfs(directions, a + !!(state & (1 << 0)), b + !!(state & (1 << 1)), c + !!(state & (1 << 2)), d + !!(state & (1 << 3)), dp));
        }
        return dp[a][b][c][d] = res;
    }

    bool ok(char a, char b, char c, char d){

        if(a == 'W' && (b == 'N' || b == 'W' || c == 'N' || d != ' ')) return false;
        if(a == 'N' && (b == 'N' || c == 'N')) return false;
        if(a == 'S' && (b == 'N' || b == 'W' || c == 'S' || c == 'E' || d == 'S' || d == 'E')) return false;

        if(b == 'N' && (c == 'E' || c == 'N' || d == 'E' || a != ' ')) return false;
        if(b == 'E' && (c == 'E' || d == 'E')) return false;
        if(b == 'W' && (c == 'E' || c == 'N' || d == 'W' || d == 'S' || a == 'W' || a == 'S')) return false;

        if(c == 'E' && (d == 'S' || d == 'E' || a == 'S' || b != ' ')) return false;
        if(c == 'S' && (d == 'S' || a == 'S')) return false;
        if(c == 'N' && (d == 'S' || d == 'E' || a == 'N' || a == 'W' || b == 'N' || b == 'W')) return false;

        if(d == 'S' && (a == 'W' || a == 'S' || b == 'W' || c != ' ')) return false;
        if(d == 'W' && (a == 'W' || b == 'W')) return false;
        if(d == 'E' && (a == 'W' || a == 'S' || b == 'E' || b == 'N' || c == 'E' || c == 'N')) return false;

        return true;
    }
};


int main() {

    vector<string> directions1 = {"W","N","ES","W"};
    cout << Solution().trafficCommand(directions1) << endl;
    // 2

    vector<string> directions2 = {"NS","WE","SE","EW"};
    cout << Solution().trafficCommand(directions2) << endl;
    // 3

    return 0;
}
