/// Source : https://leetcode.com/problems/snakes-and-ladders/description/
/// Author : liuyubobobo
/// Time   : 2018-09-25

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// BFS
/// Calculate the board position during the bfs
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        int n2 = n * n;

        vector<bool> visited(n2 + 1, false);
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        visited[1] = true;
        while(!q.empty()){
            int pos = q.front().first;
            int step = q.front().second;
            q.pop();

            if(pos == n2)
                return step;

            for(int i = 1; i <= 6 && pos + i <= n2; i ++){
                int next = pos + i;
                int x, y;
                getPos(next, x, y, n);
                if(board[x][y] != -1)
                    next = board[x][y];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(make_pair(next, step + 1));
                }
            }
        }

        return -1;
    }

private:
    void getPos(int pos, int& x, int& y, int n){

        x = (pos - 1) / n;
        y = (pos - 1) % n;
        x = n - 1 - x;
        if(x % 2 == n % 2)
            y = n - 1 - y;
    }
};


int main() {

    vector<vector<int>> board1 = {
            {-1,1,2,-1},
            {2,13,15,-1},
            {-1,10,-1,-1},
            {-1,6,2,8}
    };
    cout << Solution().snakesAndLadders(board1) << endl;
    // 2

    vector<vector<int>> board2 = {
            {-1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, 35, -1, -1, 13, -1},
            {-1, -1, -1, -1, -1, -1},
            {-1, 15, -1, -1, -1, -1}
    };
    cout << Solution().snakesAndLadders(board2) << endl;
    // 4

    return 0;
}