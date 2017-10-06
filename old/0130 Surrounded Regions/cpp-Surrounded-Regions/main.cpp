/// Created by liuyubobobo on 7/13/17.
/// Leetcode 130. Surrounded Regions
/// https://leetcode.com/problems/surrounded-regions/#/description

/***
 * This version of code uses DFS to solve the problem.
 * But this problem is amazing! Using DFS will lead to Runtime Error,
 * Because in some specific cases, the recursive depth might be too high
 *
 * The following is an example:
 * OOOOOOOOO
 * XXXXXXXXO
 * OOOOOOOXO
 * OXXXXXOXO
 * OXOOOXOXO
 * OXOXOXOXO
 * OXOXXXOXO
 * OXOOOOOXO
 * OXXXXXXXO
 * OOOOOOOOO
 *
 * We can see, in above test case, the complexity of recursive depth is O(n*m),
 * where n and m describe the size of board.
 * Obviously, it's too high!
 *
 * The Accepted code is listed in main2.cpp,
 * which uses BFS instead of DFS.
 * Feel free to check it out:)
 */


#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;
    int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

private:
    bool inArea(int x, int y){
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool dfs(vector<vector<char>> &board, int x, int y){

        visited[x][y] = true;
        board[x][y] = 'X';

        for(int i = 0; i < 4; i++){
            int newX = x + d[i][0];
            int newY = y + d[i][1];
            if (!inArea(newX, newY)){
                board[x][y] = 'O';
                return false;
            }
            if(board[newX][newY] == 'O' && !visited[newX][newY])
                if(!dfs(board, newX, newY)){
                    board[x][y] = 'O';
                    return false;
                }
        }
        return true;
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0)
            return;
        n = board[0].size();
        if( n == 0)
            return;

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if (board[i][j] == 'O' && !visited[i][j])
                    dfs(board, i, j);

        return;
    }
};

int main(){

    int n = 4, m = 4;
    string board_array[] = {
            "XXXX",
            "XOOX",
            "XXOX",
            "XOXX"};
    vector<vector<char>> board = vector<vector<char>>(n, vector<char>(m, ' '));
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            board[i][j] = board_array[i][j];

    Solution().solve(board);

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++)
            cout << board[i][j];
        cout << endl;
    }

    return 0;
}