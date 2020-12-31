/// Source : https://leetcode.com/problems/walls-and-gates/description/
/// Author : liuyubobobo
/// Time   : 2018-08-25
/// Updated: 2019-06-12

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution {

private:
    const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;

    const int GATE = 0;
    const int EMPTY = INT_MAX;
    const int WALL = -1;

public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        m = rooms.size();
        if(m == 0)
            return;
        n = rooms[0].size();

        bfs(rooms);
        return;
    }

private:
    void bfs(vector<vector<int>>& rooms){

        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(rooms[i][j] == GATE)
                    q.push(make_pair(make_pair(i, j), 0));

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while(!q.empty()){
            int curx = q.front().first.first;
            int cury = q.front().first.second;
            int step = q.front().second;
            q.pop();

            rooms[curx][cury] = step;
            for(int i = 0; i < 4; i ++){
                int newX = curx + d[i][0];
                int newY = cury + d[i][1];
                if(inArea(newX, newY) && !visited[newX][newY] && rooms[newX][newY] == EMPTY){
                    visited[newX][newY] = true;
                    rooms[newX][newY] = step + 1;
                    q.push(make_pair(make_pair(newX, newY), step + 1));
                }
            }
        }
    }

    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    return 0;
}