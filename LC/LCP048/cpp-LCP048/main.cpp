/// Source : https://leetcode-cn.com/problems/fsa7oZ/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Ad-Hoc, Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const int dirs[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

public:
    string gobang(vector<vector<int>>& pieces) {

        map<pair<int, int>, int> board;
        for(const vector<int>& piece: pieces)
            board[{piece[0], piece[1]}] = piece[2];

        // black - 0, white - 1
        set<pair<int, int>> black_win_pos = get_win_pos(board, 0);
        set<pair<int, int>> white_win_pos = get_win_pos(board, 1);

        if(black_win_pos.size()) return "Black";
        if(white_win_pos.size() >= 2) return "White";

        if(white_win_pos.size() == 1){
            board[*white_win_pos.begin()] = 0;
            black_win_pos = get_win_pos(board, 0);
            if(black_win_pos.size() >= 2) return "Black";
            return "None";
        }

        return have_black_4(board) ? "Black" : "None";
    }

private:
    bool have_black_4(const map<pair<int, int>, int>& board){

        for(const pair<pair<int, int>, int>& p: board)
            if(p.second == 0){
                int x = p.first.first, y = p.first.second;
                for(int d = 0; d < 8; d ++){
                    int color_cnt = 0, op_cnt = 0, empty_cnt = 0;
                    for(int l = 0; l < 4 && op_cnt == 0; l ++){
                        pair<int, int> np = {x + l * dirs[d][0], y + l * dirs[d][1]};
                        if(!board.count(np)) empty_cnt ++;
                        else if(board.find(np)->second == 0) color_cnt ++;
                        else op_cnt ++;
                    }
                    if(color_cnt == 3 && op_cnt == 0){
                        assert(empty_cnt == 1);
                        pair<int, int> np1 = {x + 4 * dirs[d][0], y + 4 * dirs[d][1]};
                        pair<int, int> np2 = {x - dirs[d][0], y - dirs[d][1]};
                        if(!board.count(np1) && !board.count(np2)) return true;
                    }
                }
            }
        return false;
    }

    set<pair<int, int>> get_win_pos(const map<pair<int, int>, int>& board, int color){

        set<pair<int, int>> res;
        for(const pair<pair<int, int>, int>& p: board)
            if(p.second == color){
                int x = p.first.first, y = p.first.second;
                for(int d = 0; d < 8; d ++){
                    int color_cnt = 0, op_cnt = 0, empty_cnt = 0;
                    pair<int, int> pos;
                    for(int l = 0; l < 5 && op_cnt == 0; l ++){
                        pair<int, int> np = {x + l * dirs[d][0], y + l * dirs[d][1]};
                        if(!board.count(np)) empty_cnt ++, pos = np;
                        else if(board.find(np)->second == color) color_cnt ++;
                        else op_cnt ++;
                    }
                    if(color_cnt == 4 && op_cnt == 0){
                        assert(empty_cnt == 1);
                        res.insert(pos);
                    }
                }
            }
        return res;
    }
};


int main() {

    vector<vector<int>> pieces1 = {{0, 0, 1}, {1, 1, 1}, {2, 2, 0}};
    cout << Solution().gobang(pieces1) << endl;
    // None

    vector<vector<int>> pieces2 = {{1,2,1},{1,4,1},{1,5,1},{2,1,0},{2,3,0},{2,4,0},{3,2,1},{3,4,0},{4,2,1},{5,2,1}};
    cout << Solution().gobang(pieces2) << endl;
    // Black

    return 0;
}
