/// Source : https://leetcode.com/problems/sudoku-solver/description/
/// Author : liuyubobobo
/// Time   : 2018-10-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Backtracking
/// Time Complexity: O(n^{need to fill})
/// Space Complexity: O(9*9)
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> block(9, vector<bool>(10, false));
        for(int i = 0; i < 9; i ++)
            for(int j = 0; j < 9; j ++)
                if(board[i][j] != '.'){
                    row[i][board[i][j] - '0'] = true;
                    col[j][board[i][j] - '0'] = true;
                    block[i / 3 * 3 + j / 3][board[i][j] - '0'] = true;
                }

        for(int i = 0; i < 81; i ++)
            if(board[i / 9][i % 9] == '.'){
                assert(dfs(board, i, row, col, block));
                return;
            }
    }

private:
    bool dfs(vector<vector<char>>& board, int pos,
             vector<vector<bool>>& row, vector<vector<bool>>& col,
             vector<vector<bool>>& block){

        if(pos == 81)
            return true;

        int next = pos + 1;
        for(; next < 81; next ++)
            if(board[next / 9][next % 9] == '.')
                break;

        int x = pos / 9, y = pos % 9;
        for(int i = 1; i <= 9; i ++)
            if(!row[x][i] && !col[y][i] && !block[x / 3 * 3 + y / 3][i]){
                row[x][i] = true;
                col[y][i] = true;
                block[x / 3 * 3 + y / 3][i] = true;
                board[x][y] = '0' + i;

                if(dfs(board, next, row, col, block))
                    return true;

                row[x][i] = false;
                col[y][i] = false;
                block[x / 3 * 3 + y / 3][i] = false;
                board[x][y] = '.';
            }
        return false;
    }
};


int main() {

    return 0;
}