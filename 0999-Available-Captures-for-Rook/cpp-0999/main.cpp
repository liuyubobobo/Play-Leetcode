/// Source : https://leetcode.com/problems/available-captures-for-rook/
/// Author : liuyubobobo
/// Time   : 2019-02-23

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {

private:
    const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numRookCaptures(vector<vector<char>>& board) {

        int rPos = -1;
        for(int i = 0; i < 64; i ++)
            if(board[i / 8][i % 8] == 'R'){
                rPos = i;
                break;
            }
        assert(rPos != -1);

        int res = 0;
        for(int i = 0; i < 4; i ++){

            for(int k = 1;;k++){
                int x = rPos / 8 + k * d[i][0], y = rPos % 8 + k * d[i][1];
                if(x >= 0 && x < 8 && y >= 0 && y < 8){
                    if(board[x][y] == 'p'){res ++; break;}
                    else if(board[x][y] == 'B') break;
                }
                else break;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}