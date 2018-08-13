/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-07-13

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// BFS
/// Time Complexity: O(m*n)
/// Space Complexity: O(m*n)
///
/// This problem is amazing! Because using DFS will lead to Runtime Error,
/// Because in some specific cases, the recursive depth might be too high
/// The following is an example:
/// OOOOOOOOO
/// XXXXXXXXO
/// OOOOOOOXO
/// OXXXXXOXO
/// OXOOOXOXO
/// OXOXOXOXO
/// OXOXXXOXO
/// OXOOOOOXO
/// OXXXXXXXO
/// OOOOOOOOO
///
/// We can see, in above test case, the complexity of recursive depth is O(n*m),
/// where n and m describe the size of board.
/// Obviously, it's too high!
class Solution {
private:
    int m, n;
    int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

private:
    bool inArea(int x, int y){
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool bfs(const vector<vector<char>> &board, int x, int y,
             vector<vector<bool>>& visited, vector<pair<int,int>>& record){

        queue<pair<int,int>> q;

        // return true if we can only get to 'X' during BFS,
        // otherwise, return false
        bool ret = true;

        visited[x][y] = true;
        q.push(pair<int,int>(x, y));
        while( !q.empty()){
            pair<int, int> cur = q.front();
            q.pop();
            record.push_back(pair<int, int>(cur.first, cur.second));

            for(int i = 0 ; i < 4 ;i ++){
                int newX = cur.first + d[i][0];
                int newY = cur.second + d[i][1];

                if(!inArea(newX, newY))
                    // If newX, newY is not in the area,
                    // it means we get out of the board in this BFS,
                    // we need to return false in this case
                    ret = false;
                else if(board[newX][newY] == 'O' && !visited[newX][newY]){
                    visited[newX][newY] = true;
                    q.push(pair<int, int>(newX, newY));
                }
            }
        }

        return ret;
    }

public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0)
            return;
        n = board[0].size();
        if(n == 0)
            return;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int,int>> record;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O' && !visited[i][j]){
                    // clear record before each time we run BFS
                    record.clear();
                    if(bfs(board, i, j, visited, record))
                        // If BFS return true,
                        // means from this position,
                        // we will not get out of the board.
                        // As a result, we can make every position we visited in this BFS from 'O' to 'X'
                        for(int k = 0 ; k < record.size() ; k ++)
                            board[record[k].first][record[k].second] = 'X';
                }

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