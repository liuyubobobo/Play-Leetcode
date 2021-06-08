/// Source : https://leetcode.com/problems/the-maze-ii/
/// Author : liuyubobobo
/// Time   : 2021-06-08

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(nlogn) where n = R * C
/// Space Complexity: O(R * C)
class Solution {

private:
    int R, C;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {

        R = maze.size(), C = maze[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<vector<int>> dis(R, vector<int>(C, INT_MAX));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start[0] * C + start[1]});
        dis[start[0]][start[1]] = 0;
        while(!pq.empty()){
            int x = pq.top().second / C, y = pq.top().second % C, d = pq.top().first;
            pq.pop();

            if(visited[x][y]) continue;

            visited[x][y] = true;

            if(x == destination[0] && y == destination[1])
                return dis[x][y];

            for(int i = 0; i < 4; i ++){
                int nx, ny;
                int dd = go(maze, x, y, nx, ny, i);
                if(!visited[nx][ny] && dis[x][y] + dd < dis[nx][ny]){
                    dis[nx][ny] = dis[x][y] + dd;
                    pq.push({dis[nx][ny], nx * C + ny});
                }
            }
        }
        return -1;
    }

private:
    int go(const vector<vector<int>>& maze, int cx, int cy, int& nx, int& ny, int d){

        nx = cx, ny = cy;
        int res = 0;
        while(in_area(nx + dirs[d][0], ny + dirs[d][1]) && maze[nx + dirs[d][0]][ny + dirs[d][1]] == 0)
            nx += dirs[d][0], ny += dirs[d][1], res ++;
        return res;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    return 0;
}
