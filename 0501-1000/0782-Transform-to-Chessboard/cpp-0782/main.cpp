/// Source : https://leetcode.com/problems/transform-to-chessboard/
/// Author : liuyubobobo
/// Time   : 2021-09-26

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Mathematics
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {

        int n = board.size();

        vector<int> total(2, 0);
        vector<vector<int>> row(n, vector<int>(2, 0)), col(n, vector<int>(2, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++){
                if(board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j])
                    return -1;
                total[board[i][j]] ++;
                row[i][board[i][j]] ++;
                col[j][board[i][j]] ++;
            }

        if(n % 2 == 0 && total[0] != total[1]) return -1;
        if(n % 2 == 1 && abs(total[0] - total[1]) > 1) return -1;

        if(n % 2 == 0){
            for(int i = 0; i < n; i ++)
                if(row[i][0] != row[i][1] || col[i][0] != col[i][1])
                    return -1;
        }
        else{
            for(int i = 0; i < n; i ++)
                if(abs(row[i][0] - row[i][1]) > 1 || abs(col[i][0] - col[i][1]) > 1)
                    return -1;
        }

        vector<int> a(n), b(n);
        a = board[0];
        for(int i = 0; i < n; i ++) b[i] = board[i][0];

        return check(n, a, b);
    }

private:
    int check(int n, const vector<int>& a, const vector<int>& b){

        int ares = 0;
        for(int i = 0; i < n; i += 2){
            if(a[i] != 0) ares ++;
            if(i + 1 < n && a[i + 1] != 1) ares ++;
        }

        int bres = 0;
        for(int i = 0; i < n; i += 2){
            if(b[i] != 0) bres ++;
            if(i + 1 < n && b[i + 1] != 1) bres ++;
        }

        if(ares % 2 || (n % 2 == 0 && n - ares < ares)) ares = n - ares;
        if(bres % 2 || (n % 2 == 0 && n - bres < bres)) bres = n - bres;
        return (ares + bres) / 2;
    }
};


int main() {

    vector<vector<int>> board1 = {
            {0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}
    };
    cout << Solution().movesToChessboard(board1) << endl;
    // 2

    vector<vector<int>> board2 = {
            {1,1,0},{0,0,1},{0,0,1}
    };
    cout << Solution().movesToChessboard(board2) << endl;
    // 2

    vector<vector<int>> board3 = {
            {1,0,0},{0,1,1},{1,0,0}
    };
    cout << Solution().movesToChessboard(board3) << endl;
    // 1

    vector<vector<int>> board4 = {
            {0,0,1,0,1,0,1,1},
            {1,1,0,1,0,1,0,0},
            {0,0,1,0,1,0,1,1},
            {1,1,0,1,0,1,0,0},
            {1,1,0,1,0,1,0,0},
            {0,0,1,0,1,0,1,1},
            {0,0,1,0,1,0,1,1},
            {1,1,0,1,0,1,0,0}
    };
    cout << Solution().movesToChessboard(board4) << endl;
    // 2

    vector<vector<int>> board5 = {
            {0,0,1,0,1,1},
            {1,1,0,1,0,0},
            {1,1,0,1,0,0},
            {0,0,1,0,1,1},
            {1,1,0,1,0,0},
            {0,0,1,0,1,1}
    };
    cout << Solution().movesToChessboard(board5) << endl;
    // 2

    return 0;
}
