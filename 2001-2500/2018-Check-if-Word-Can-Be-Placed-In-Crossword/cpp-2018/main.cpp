/// Source : https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    int R, C;

public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {

        R = board.size(), C = board[0].size();

        string p = "";
        for(int i = 0; i < R; i ++){
            p = "";
            for(int j = 0; j < C; j ++)
                if(board[i][j] != '#' && (j == 0 || board[i][j - 1] == '#')){
                    int k;
                    for(k = j; k < C && board[i][k] != '#'; k ++)
                        p += board[i][k];
//                    cout << "(" << p << ") " << p.size() << endl;
                    if(ok(p, word)) return true;
                    j = k;
                    p = "";
                }
        }

        for(int j = 0; j < C; j ++){
            p = "";
            for(int i = 0; i < R; i ++)
                if(board[i][j] != '#' && (i == 0 || board[i - 1][j] == '#')){
                    int k;
                    for(k = i; k < R && board[k][j] != '#'; k ++)
                        p += board[k][j];
//                    cout << "(" << p << ") " << p.size() << endl;
                    if(ok(p, word)) return true;
                    i = k;
                    p = "";
                }
        }

        return false;
    }

private:
    bool ok(const string& p, const string& word){

//        cout << "(" << p << ") " << p.size() << endl;

        if(p.size() != word.size()) return false;

        bool ok = true;
        for(int i = 0; i < p.size(); i ++)
            if(p[i] != ' ' && p[i] != word[i]){
                ok = false;
                break;
            }

        if(ok) return true;

        string word2 = word;
        reverse(word2.begin(), word2.end());
        for(int i = 0; i < p.size(); i ++)
            if(p[i] != ' ' && p[i] != word2[i])
                return false;

        return true;
    }
};


int main() {

    vector<vector<char>> board2 = {{' ', '#', 'a'}, {' ', '#', 'c'}, {' ', '#', 'a'}};
    cout << Solution().placeWordInCrossword(board2, "ac") << endl;
    // 0

    vector<vector<char>> board3 = {{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', ' ', 'c'}};
    cout << Solution().placeWordInCrossword(board3, "ca") << endl;
    // 1

    vector<vector<char>> board4 = {{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', 'c', ' '}};
    cout << Solution().placeWordInCrossword(board4, "abc") << endl;
    // 1

    return 0;
}
