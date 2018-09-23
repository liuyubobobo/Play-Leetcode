/// Source : https://leetcode.com/problems/snakes-and-ladders/description/
/// Author : liuyubobobo
/// Time   : 2018-09-22

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// BFS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        vector<int> b;

        int order = 0;
        for(int i = n - 1; i >= 0; i --){
            if(order)
                reverse(board[i].begin(), board[i].end());
            for(int j = 0; j < n; j ++){
                if(board[i][j] != -1)
                    board[i][j] --;
                b.push_back(board[i][j]);
            }
            order = 1 - order;
        }
        assert(b.size() == n * n);

        return bfs(b, 0, n * n - 1);
    }

private:
    int bfs(const vector<int>& b, int s, int t){

        vector<bool> visited(b.size(), false);
        queue<pair<int, int>> q;
        q.push(make_pair(s, 0));
        visited[s] = true;
        while(!q.empty()){
            int pos = q.front().first;
            int step = q.front().second;
            q.pop();

            if(pos == t)
                return step;

            for(int i = 1; i <= 6 && pos + i < b.size(); i ++){
                int next = pos + i;
                if(b[next] != -1)
                    next = b[next];
                if(!visited[next]){
                    visited[next] = true;
                    q.push(make_pair(next, step + 1));
                }
            }
        }

        return -1;
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

    return 0;
}