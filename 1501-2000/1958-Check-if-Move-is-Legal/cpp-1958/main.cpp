/// Source : https://leetcode.com/problems/check-if-move-is-legal/
/// Author : liuyubobobo
/// Time   : 2021-08-07

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(R * C)
/// Space Complexity: O(max(R, C))
class Solution {

private:
    const int dirs[8][2] = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };
    int R, C;

public:
    bool checkMove(vector<vector<char>>& board, int r, int c, char color) {

        R = board.size(), C = board[0].size();

        board[r][c] = color;
        for(int d = 0; d < 8; d ++){
            vector<char> v;
            for(int k = 0;;k++){
                int x = r + k * dirs[d][0], y = c + k * dirs[d][1];
                if(!in_area(x, y) || board[x][y] == '.') break;
                v.push_back(board[x][y]);
            }
            if(ok(v)) return true;
        }
        return false;
    }

private:
    bool ok(const vector<char>& v){

        if(v.size() < 3) return false;
        if(v[1] == v[0]) return false;

        vector<int> seg;
        for(int start = 0, i = 1; i <= v.size(); i ++)
            if(i == v.size() || v[i] != v[start]){
                seg.push_back(i - start);
                start = i;
                i = start;
            }

        return seg.size() >= 3;
    }
    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    return 0;
}
