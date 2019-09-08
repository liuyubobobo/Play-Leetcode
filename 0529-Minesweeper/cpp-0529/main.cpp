/// Source : https://leetcode.com/problems/minesweeper/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n * m)
/// Space Complexity: O(n * m)
class Solution {

private:
    int n, m;

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }

        n = board.size(), m = board[0].size();
        go(board, click[0], click[1]);
        return board;
    }

private:
    void go(vector<vector<char>>& board, int x, int y){

        int res = 0;
        for(int dx = -1; dx <= 1; dx ++)
            for(int dy = -1; dy <= 1; dy ++)
                if((dx || dy) && in_area(x + dx, y + dy))
                    res += (board[x + dx][y + dy] == 'M');

        if(res){
            board[x][y] = '0' + res;
            return;
        }

        board[x][y] = 'B';
        for(int dx = -1; dx <= 1; dx ++)
            for(int dy = -1; dy <= 1; dy ++)
                if((dx || dy) && in_area(x + dx, y + dy) && board[x + dx][y + dy] == 'E')
                    go(board, x + dx, y + dy);
    }

    bool in_area(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


void print_board(const vector<vector<char>>& board){
    for(const vector<char>& v: board){
        for(char c: v) cout << c << " ";
        cout << endl;
    }
}

int main() {

    vector<vector<char>> board1 = {
            {'E', 'E', 'E', 'E', 'E'},
            {'E', 'E', 'M', 'E', 'E'},
            {'E', 'E', 'E', 'E', 'E'},
            {'E', 'E', 'E', 'E', 'E'}
    };
    vector<int> click1 = {3, 0};
    print_board(Solution().updateBoard(board1, click1));

    return 0;
}