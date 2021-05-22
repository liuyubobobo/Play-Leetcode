/// Source : https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
/// Author : liuyubobobo
/// Time   : 2021-05-22

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: init: O(1)
///                  move: O(n)
/// Space Complexity: O(n^2)
class TicTacToe {

private:
    vector<vector<int>> board;
    int n, winner;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n), board(n, vector<int>(n, 0)), winner(0){
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {

        if(winner) return winner;

        board[row][col] = player;

        int j;
        for(j = 0; j < n; j ++)
            if(board[row][j] != player)
                break;
        if(j == n){winner = player; return player;}

        int i;
        for(i = 0; i < n; i ++)
            if(board[i][col] != player)
                break;
        if(i == n){winner = player; return player;}

        if(row == col){
            for(i = 0, j = 0; i < n && j < n; i ++, j ++)
                if(board[i][j] != player)
                    break;
            if(i == n){winner = player; return player;}
        }

        if(row + col == n - 1){
            for(i = 0, j = n - 1; i < n && j >= 0; i ++, j --)
                if(board[i][j] != player)
                    break;
            if(i == n){winner = player; return player;}
        }

        return 0;
    }
};


int main() {

    return 0;
}
