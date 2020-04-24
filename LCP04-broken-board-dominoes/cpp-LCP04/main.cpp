/// Source : https://leetcode-cn.com/problems/broken-board-dominoes/
/// Author : liuyubobobo
/// Time   : 2020-04-22

#include <iostream>
#include <vector>

using namespace std;


/// State Compression DP
/// Time Complexity: O(n * m * 2^m)
/// Space Complexity: O(n * m * 2^m)
class Solution {

private:
    int n, m;
    vector<int> board;

public:
    int domino(int n, int m, vector<vector<int>>& broken) {

        this->n = n;
        this->m = m;

        board.resize(n, 0);
        for(const vector<int>& p: broken)
            board[p[0]] |= (1 << p[1]);

        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m,
                vector<vector<int>>(1<<m, vector<int>(1<<m, -1))));
        return go(0, 0, board[0], n == 1 ? (1<<m) - 1 : board[1], dp);
    }

private:
    int go(int x, int y, int cur, int next, vector<vector<vector<vector<int>>>>& dp){

        if(x == n - 1 && y >= m) return 0;
        if(y >= m) return go(x + 1, 0, next, x + 1 == n - 1 ? (1 << m) - 1 : board[x + 2], dp);
        if(dp[x][y][cur][next] != -1) return dp[x][y][cur][next];

        int res = go(x, y + 1, cur, next, dp);

        if((cur & (1 << y)) == 0 && y + 1 < m && (cur & (1 << (y + 1))) == 0){
            int next_cur = cur;
            next_cur |= (1 << y);
            next_cur |= (1 << (y + 1));
            res = max(res, 1 + go(x, y + 2, next_cur, next, dp));
        }

        if((cur & (1 << y)) == 0 && x + 1 < n && (next & (1 << y)) == 0)
            res = max(res, 1 + go(x, y + 1, cur | (1 << y), next | (1 << y), dp));

//        cout << x << " " << y << " " << cur << " " << next << " : " << res << endl;
        return dp[x][y][cur][next] = res;
    }
};


int main() {

    vector<vector<int>> broken1 = {{1, 0}, {1, 1}};
    cout << Solution().domino(2, 3, broken1) << endl;
    // 2

    vector<vector<int>> broken2 = {};
    cout << Solution().domino(3, 3, broken2) << endl;
    // 4

    return 0;
}