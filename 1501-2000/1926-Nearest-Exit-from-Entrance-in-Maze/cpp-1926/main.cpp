/// Source : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
/// Author : liuyubobobo
/// Time   : 2021-07-11

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        R = maze.size(), C = maze[0].size();
        vector<vector<int>> dis(R, vector<int>(C, -1));

        queue<int> q;
        q.push(entrance[0] * C + entrance[1]);
        dis[entrance[0]][entrance[1]] = 0;
        while(!q.empty()){
            int x = q.front() / C, y = q.front() % C;
            q.pop();

            for(int d = 0; d < 4; d ++){
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if(in_area(nx, ny) && dis[nx][ny] == -1 && maze[nx][ny] == '.'){
                    dis[nx][ny] = dis[x][y] + 1;
                    if(nx == 0 || nx == R - 1 || ny == 0 || ny == C - 1)
                        return dis[nx][ny];
                    q.push(nx * C + ny);
                }
            }
        }
        return -1;
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    return 0;
}
