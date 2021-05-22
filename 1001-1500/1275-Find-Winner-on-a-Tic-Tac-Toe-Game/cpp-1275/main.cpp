/// Source : https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
/// Author : liuyubobobo
/// Time   : 2021-05-22

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(|moves|)
/// Space Complexity: O(1)
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {

        vector<vector<int>> board(3, vector<int>(3, 0));
        for(int i = 0; i < moves.size(); i ++){
            int x = moves[i][0], y = moves[i][1], player = i % 2 + 1;
            board[x][y] = player;
            if(win(board, x, y)) return player == 1 ? "A" : "B";
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }

private:
    bool win(const vector<vector<int>>& board, int x, int y){

        if(board[x][0] == board[x][1] && board[x][1] == board[x][2])
            return true;

        if(board[0][y] == board[1][y] && board[1][y] == board[2][y])
            return true;

        if(x == y && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;

        if(x + y == 2 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;

        return false;
    }
};


int main() {

    return 0;
}
