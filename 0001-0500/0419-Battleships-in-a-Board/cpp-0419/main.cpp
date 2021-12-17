/// Source : https://leetcode.com/problems/battleships-in-a-board/
/// Author : liuyubobobo
/// Time   : 2021-12-17

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {

        int R = board.size(), C = board[0].size(), res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(board[i][j] == '.') continue;

                int tres = (i + 1 < R && board[i + 1][j] == 'X') + (j + 1 < C && board[i][j + 1] == 'X');
                if(tres == 0) tres = 1;
                res += tres;

                for(int k = j + 1; k < C && board[i][k] == 'X'; k ++) board[i][k] = '.';
                for(int k = i + 1; k < R && board[k][j] == 'X'; k ++) board[k][j] = '.';
                board[i][j] = '.';
            }
        return res;
    }
};


int main() {

    return 0;
}
