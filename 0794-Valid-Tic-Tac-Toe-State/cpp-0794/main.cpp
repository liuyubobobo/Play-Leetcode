/// Source : https://leetcode.com/problems/valid-tic-tac-toe-state/description/
/// Author : liuyubobobo
/// Time   : 2018-03-03

#include <iostream>
#include <vector>
#include <string>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {

        int x_num = 0, o_num = 0;
        for(int i = 0 ; i < board.size() ; i ++)
            for(int j = 0 ; j < board[i].size() ; j ++)
                if(board[i][j] == 'X')
                    x_num ++;
                else if(board[i][j] == 'O')
                    o_num ++;

        if(abs(x_num - o_num) >= 2)
            return false;

        //cout << "x: " << x_num << " o: " << o_num << endl;
        bool X_win = win(board, 'X');
        bool O_win = win(board, 'O');

        if(X_win && O_win){
            //cout << "X_win && O_win" << endl;
            return false;
        }
        else if(!X_win && !O_win){
            //cout << "!X_win && !O_win" << endl;
            return x_num >= o_num;
        }
        else if(X_win && !O_win){
            //cout << "X_win && !O_win" << endl;
            return x_num > o_num;
        }
        else{ // !X_win && O_win
            //cout << "!X_win && O_win" << endl;
            return o_num == x_num;
        }
    }

private:
    bool win(const vector<string>& board, char c){

        for(int i = 0 ; i < 3 ; i ++){
            if(board[i][1] == board[i][0] && board[i][2] == board[i][1] && board[i][0] == c)
                return true;
            if(board[1][i] == board[0][i] && board[2][i] == board[1][i] && board[0][i] == c)
                return true;
        }

        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == c)
            return true;

        if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == c)
            return true;

        return false;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<string> board1 = {"O  ", "   ", "   "};
    printBool(Solution().validTicTacToe(board1));
    // false

    vector<string> board2 = {"XOX", " X ", "   "};
    printBool(Solution().validTicTacToe(board2));
    // false

    vector<string> board3 = {"XXX", "   ", "OOO"};
    printBool(Solution().validTicTacToe(board3));
    // false

    vector<string> board4 = {"XOX", "O O", "XOX"};
    printBool(Solution().validTicTacToe(board4));
    // true

    vector<string> board5 = {"XXX","XOO","OO "};
    printBool(Solution().validTicTacToe(board5));
    // false

    vector<string> board6 = {"X  ","X  ","O O"};
    printBool(Solution().validTicTacToe(board6));
    // true

    return 0;
}