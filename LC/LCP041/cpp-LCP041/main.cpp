/// Source : https://leetcode-cn.com/problems/fHi6rV/
/// Author : liuyubobobo
/// Time   : 2021-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O((R * C)^3)
/// Space Complexity: O(R * C)
class Solution {

private:
    int R, C;
    const int dirs[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

public:
    int flipChess(vector<string>& chessboard) {

        R = chessboard.size(), C = chessboard[0].size();

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(chessboard[i][j] == '.'){
                    vector<string> t = chessboard;
                    t[i][j] = 'X';
                    vector<vector<bool>> visited(R, vector<bool>(C, false));
                    visited[i][j] = true;
                    res = max(res, check(t, i, j, visited));
                }
        return res;
    }

private:
    int check(vector<string>& board, int x, int y, vector<vector<bool>>& visited){

        vector<pair<int, int>> next;

        int res = 0;
        for(int d = 0; d < 8; d ++){

            int cx = x + dirs[d][0], cy = y + dirs[d][1], t = 0;
            while(in_area(cx, cy) && board[cx][cy] != 'X')
                cx += dirs[d][0], cy += dirs[d][1], t ++;

            if(in_area(cx, cy) && board[cx][cy] == 'X'){
                int tx = x + dirs[d][0], ty = y + dirs[d][1];
                vector<pair<int, int>> tnext;
                while(tx != cx || ty != cy){
                    if(board[tx][ty] != 'O') break;
                    tnext.push_back({tx, ty});
                    tx += dirs[d][0], ty += dirs[d][1];
                }
                if(tx == cx && ty == cy){
                    res += t;
                    for(const pair<int, int>& p: tnext){
                        if(!visited[p.first][p.second]){
                            visited[p.first][p.second] = true;
                            next.push_back(p);
                        }
                        board[p.first][p.second] = 'X';
                    }
                }
            }
        }

        for(const pair<int, int>& p: next)
            res += check(board, p.first, p.second, visited);
        return res;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<string> chessboard1 = {"....X.","....X.","XOOO..","......","......"};
    cout << Solution().flipChess(chessboard1) << endl;
    // 3

    vector<string> chessboard2 = {".X.",".O.","XO."};
    cout << Solution().flipChess(chessboard2) << endl;
    // 2

    vector<string> chessboard3 = {".......",".......",".......","X......",".O.....","..O....","....OOX"};
    cout << Solution().flipChess(chessboard3) << endl;
    // 4

    return 0;
}
