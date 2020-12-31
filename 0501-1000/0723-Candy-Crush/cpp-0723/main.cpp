/// Source : https://leetcode.com/problems/candy-crush/description/
/// Author : liuyubobobo
/// Time   : 2017-11-04

#include <iostream>
#include <vector>

using namespace std;

/// Ad-Hoc
/// Time Complexity: O((r*c)^2) where r is row number, c is column number
/// Space Complexity: O(1)
class Solution {

private:
    int n, m;

public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {

        if(board.size() == 0)
            return board;

        n = board.size();
        m = board[0].size();

        while(match(board)){
//            cout << "After match:" << endl;
//            printBoard(board);
//            cout << endl;

            drop(board);

//            cout << "After Drop:" << endl;
//            printBoard(board);
//            cout << endl;
        }

//        printBoard(board);

        return board;
    }

private:
    bool match(vector<vector<int>>& board){

        bool ret = false;
        vector<vector<bool>> mask(n, vector<bool>(m, false));
        for(int i = 0 ; i < n ; i ++ ){
            for(int j = 0 ; j < m ; j ++){
                if(board[i][j] != 0){
                    if(j + 2 < m && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2]){
                        for(int k = 0 ; k < 3 ; k ++)
                            mask[i][j + k] = true;
                        ret = true;
                    }
                    if(i + 2 < n && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j]){
                        for(int k = 0 ; k < 3 ; k ++)
                            mask[i + k][j] = true;
                        ret = true;
                    }
                }
            }
        }

        if(ret)
            for(int i = 0 ; i < n ; i ++)
                for(int j = 0 ; j < m ; j ++)
                    if(mask[i][j])
                        board[i][j] = 0;

        return ret;
    }

    void drop(vector<vector<int>>& board){

        for(int j = 0 ; j < m ; j ++){

            int index = n-1;
            for(int i = n-1 ; i >= 0 ; i--)
                if(board[i][j] != 0){
                    board[index][j] = board[i][j];
                    index --;
                }

            for(int i = index ; i >= 0 ; i --)
                board[i][j] = 0;
        }

        return;
    }
};

void printBoard(const vector<vector<int>>& board){

    for(int i = 0 ; i < board.size() ; i ++){
        for(int j = 0 ; j < board[i].size() ; j ++)
            cout << board[i][j] << "\t";
        cout << endl;
    }
}

int main() {

    int n = 10, m = 5;
    int board[10][5] = {
            {110,5,112,113,114},
            {210,211,5,213,214},
            {310,311,3,313,314},
            {410,411,412,5,414},
            {5,1,512,3,3},
            {610,4,1,613,614},
            {710,1,2,713,714},
            {810,1,2,1,1},
            {1,1,2,2,2},
            {4,1,4,4,1014}};
    vector<vector<int>> vec;
    for(int i = 0 ; i < n ; i ++)
        vec.push_back(vector<int>(board[i], board[i] + m));
    printBoard(Solution().candyCrush(vec));

    return 0;

}