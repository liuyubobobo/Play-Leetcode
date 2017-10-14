/// Source : https://leetcode.com/problems/word-search/description/
/// Author : liuyubobobo
/// Time   : 2017-05-05

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 回溯法
// 时间复杂度: O(m*n*m*n)
// 空间复杂度: O(m*n)
class Solution {

private:
    int d[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
    int m, n;
    vector<vector<bool>> visited;

    bool inArea( int x , int y ){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // 从board[startx][starty]开始, 寻找word[index...word.size())
    bool searchWord( const vector<vector<char>> &board, const string& word, int index,
                    int startx, int starty ){

        //assert( inArea(startx,starty) );
        if( index == word.size() - 1 )
            return board[startx][starty] == word[index];

        if( board[startx][starty] == word[index] ){
            visited[startx][starty] = true;
            // 从startx, starty出发,向四个方向寻
            for( int i = 0 ; i < 4 ; i ++ ){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if( inArea(newx, newy) && !visited[newx][newy] &&
                    searchWord(board, word, index + 1, newx, newy))
                    return true;
            }
            visited[startx][starty] = false;
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        assert( m > 0 );
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for( int i = 0 ; i < board.size() ; i ++ )
            for( int j = 0 ; j < board[i].size() ; j ++ )
                if( searchWord( board, word, 0 , i, j) )
                    return true;

        return false;
    }
};

int main() {

    char b1[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board1;
    for( int i = 0 ; i < 3 ; i ++ )
        board1.push_back(vector<char>(b1[i], b1[i] + sizeof(b1[i]) / sizeof(char)));

    int cases = 3;
    string words[3] = {"ABCCED" , "SEE" , "ABCB" };
    for( int i = 0 ; i < cases ; i ++ )
        if(Solution().exist(board1,words[i]))
            cout<<"found "<<words[i]<<endl;
        else
            cout<<"can not found "<<words[i]<<endl;

    // ---

    char b2[1][1] = {{'A'}};
    vector<vector<char>> board2;
    for(int i = 0 ; i < 3 ; i ++)
        board2.push_back(vector<char>(b2[i],b2[i]+sizeof(b2[i])/sizeof(char)));

    if(Solution().exist(board2,"AB"))
        cout<<"found AB"<<endl;
    else
        cout<<"can not found AB"<<endl;

    return 0;
}