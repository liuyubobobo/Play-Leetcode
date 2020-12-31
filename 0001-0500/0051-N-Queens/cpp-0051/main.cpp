/// Source : https://leetcode.com/problems/n-queens/description/
/// Author : liuyubobobo
/// Time   : 2017-11-18

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Basic Recursive
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {
private:
    vector<bool> col, dia1, dia2;
    vector<vector<string>> res;

    // 尝试在一个n皇后问题中, 摆放第index行的皇后位置
    void putQueen(int n, int index, vector<int> &row){

        if(index == n){
            res.push_back(generateBoard(n, row));
            return;
        }

        for(int i = 0 ; i < n ; i ++)
            // 尝试将第index行的皇后摆放在第i列
            if(!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]){
                row.push_back(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;
                putQueen(n, index + 1, row);
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                row.pop_back();
            }

        return;
    }

    vector<string> generateBoard(int n, vector<int> &row){
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for(int i = 0 ; i < n ; i ++)
            board[i][row[i]] = 'Q';
        return board;
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        res.clear();

        col.clear();
        for(int i = 0 ; i < n ; i ++)
            col.push_back(false);

        dia1.clear();
        dia2.clear();
        for(int i = 0 ; i < 2 * n - 1 ; i ++){
            dia1.push_back(false);
            dia2.push_back(false);
        }

        vector<int> row;
        putQueen(n, 0, row);

        return res;
    }
};


void printBoard(const vector<string>& board){
    for(string row: board)
        cout << row << endl;
    cout << endl;
}

int main() {

    int n = 4;
    vector<vector<string>> res = Solution().solveNQueens(n);
    for(vector<string> board: res)
        printBoard(board);

    return 0;
}