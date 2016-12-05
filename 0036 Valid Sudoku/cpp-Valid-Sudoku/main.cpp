/// Source : https://leetcode.com/problems/valid-sudoku/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Problem
/*****************************************************************************************************
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * http://sudoku.com.au/TheRules.aspx
 *
 * The Sudoku board could be partially filled,
 * where empty cells are filled with the character '.'.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable.
 * Only the filled cells need to be validated.
 *****************************************************************************************************/


/// Solution
/**************************************************************************************
 * Using hashtable to check every row, column and block.
 *
 * Time Complexity: O(9*9)
 * Space Complexity: O(1)
 **************************************************************************************/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        assert( board.size() == 9 );
        for( int i = 0 ; i < 9 ; i ++ ){
            assert( board[i].size() == 9 );
            for( int j = 0 ; j < 9 ; j ++ )
                assert( board[i][j] == '.' || ( board[i][j] >= '1' && board[i][j] <= '9')) ;
        }


        bool hashtable[9][9];

        // check for every row
        memset( hashtable, 0, sizeof(hashtable));
        for( int i = 0 ; i < 9 ; i ++ )
            for( int j = 0 ; j < 9 ; j ++ )
                if( board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1;
                    if( hashtable[i][num] == 1 )
                        return false;
                    hashtable[i][num] = 1;
                }

        // check for every col
        memset( hashtable, 0, sizeof(hashtable));
        for( int i = 0 ; i < 9 ; i ++ )
            for( int j = 0 ; j < 9 ; j ++ )
                if( board[j][i] != '.'){
                    int num = board[j][i] - '0' - 1;
                    if( hashtable[i][num] == 1 )
                        return false;
                    hashtable[i][num] = 1;
                }

        // check for every block
        memset( hashtable, 0, sizeof(hashtable));
        for( int i = 0 ; i < 9 ; i ++ ){
            int br = i/3;
            int bc = i%3;
            for( int ii = 0 ; ii < 3 ; ii ++ )
                for( int jj = 0 ; jj < 3 ; jj ++ ){

                    int r = br*3 + ii;
                    int c = bc*3 + jj;
                    if( board[r][c] != '.') {
                        int num = board[r][c] - '0' - 1;
                        if ( hashtable[i][num] == 1 )
                            return false;
                        hashtable[i][num] = 1;
                    }
                }
        }

        return true;
    }
};

int main() {

    char b[9][10] = {
            "53..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"
    };

    vector<vector<char>> board;
    for( int i = 0 ; i < 9 ; i ++ ){
        vector<char> row;
        for( int j = 0 ; j < 9 ; j ++ )
            row.push_back( b[i][j] );
        board.push_back( row );
    }

    cout<<Solution().isValidSudoku(board)<<endl;

    return 0;
}