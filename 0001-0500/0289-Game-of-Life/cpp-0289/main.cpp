/// Source : https://leetcode.com/problems/game-of-life/
/// Author : liuyubobobo
/// Time   : 2020-12-30
/// Updated: 2022-04-11

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

public:
    void gameOfLife(vector<vector<int>>& board) {

        int R = board.size(), C = board[0].size();
        vector<vector<int>> res(R, vector<int>(C, 0));

        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){

                int num = 0;
                for(int ii = max(0, i - 1); ii <= min(i + 1, R - 1); ii ++)
                    for(int jj = max(0, j - 1); jj <= min(j + 1, C - 1); jj ++){
                        if(ii == i && jj == j) continue;
                        num += board[ii][jj];
                    }

                if(board[i][j]){
                    if(num < 2 || num > 3) res[i][j] = 0;
                    else res[i][j] = 1;
                }
                else{
                    if(num == 3) res[i][j] = 1;
                }
            }

        board = res;
    }
};


int main() {

    return 0;
}
