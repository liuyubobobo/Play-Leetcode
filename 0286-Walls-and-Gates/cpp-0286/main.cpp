/// Source : https://leetcode.com/problems/walls-and-gates/description/
/// Author : liuyubobobo
/// Time   : 2018-08-25

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution {

private:
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;

public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        n = rooms.size();
        if(n == 0)
            return;
        m = rooms[0].size();
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(rooms[i][j] == 0)
                    bfs(rooms, i, j);
        return;
    }

private:
    void bfs(vector<vector<int>>& rooms, int startx, int starty){

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(startx, starty), 0));
        visited[startx][starty] = true;
        while(!q.empty()){
            int curx = q.front().first.first;
            int cury = q.front().first.second;
            int step = q.front().second;
            q.pop();

            rooms[curx][cury] = step;
            for(int i = 0; i < 4; i ++){
                int newX = curx + d[i][0];
                int newY = cury + d[i][1];
                if(inArea(newX, newY) && !visited[newX][newY] && rooms[newX][newY] >= 0){
                    visited[newX][newY] = true;
                    if(rooms[newX][newY] > step + 1){
                        rooms[newX][newY] = step + 1;
                        q.push(make_pair(make_pair(newX, newY), step + 1));
                    }
                }
            }
        }
    }

    bool inArea(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


int main() {

    return 0;
}