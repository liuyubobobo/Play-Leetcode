/// Source : https://leetcode.cn/problems/rdmXM7/
/// Author : liuyubobobo
/// Time   : 2023-04-22

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS + Dijkstra
/// Time Complexity: O(n^2 * log(n^2))
/// Space Complexity: O(n^2)
class Solution {

private:
    int R, C;
    const int INF = INT_MAX / 2;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int challengeOfTheKeeper(vector<string>& maze) {

        R = maze.size(), C = maze[0].size();

        int sx = -1, sy = -1, tx = -1, ty = -1;
        for(int i = 0; i < R && (sx == -1 || tx == -1); i ++)
            for(int j = 0; j < C && (sx == -1 || tx == -1); j ++)
                if(maze[i][j] == 'S') sx = i, sy = j;
                else if(maze[i][j] == 'T') tx = i, ty = j;

        vector<vector<int>> tdis = bfs(maze, tx, ty);
        if(tdis[sx][sy] == INF) return -1;

        vector<vector<int>> w(R, vector<int>(C, INF));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(maze[i][j] == 'S' || maze[i][j] == 'T'){
                    w[i][j] = 0; continue;
                }
                if(maze[i][j] == '#') continue;

                int res = 0;
                if(maze[R - 1 - i][j] != '#') res = max(res, tdis[R - 1 - i][j]);
                if(maze[i][C - 1 - j] != '#') res = max(res, tdis[i][C - 1 - j]);
                w[i][j] = res;
            }

        vector<vector<int>> res = dij(maze, w, sx, sy);
        return res[tx][ty] == INF ? -1 : res[tx][ty];
    }

private:
    vector<vector<int>> dij(const vector<string>& maze, const vector<vector<int>>& w, int sx, int sy){

        vector<vector<int>> dis(R, vector<int>(C, INF));
        dis[sx][sy] = 0;
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, sx * C + sy});
        while(!pq.empty()){
            int cd = pq.top().first, cx = pq.top().second / C, cy = pq.top().second % C; pq.pop();

            if(visited[cx][cy]) continue;
            visited[cx][cy] = true;

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(in_area(nx, ny) && maze[nx][ny] != '#' && dis[nx][ny] > max(cd, w[nx][ny])){
                    dis[nx][ny] = max(cd, w[nx][ny]);
                    pq.push({dis[nx][ny], nx * C + ny});
                }
            }
        }
        return dis;
    }

    vector<vector<int>> bfs(const vector<string>& maze, int sx, int sy){

        vector<vector<int>> dis(R, vector<int>(C, INF));
        dis[sx][sy] = 0;
        queue<pair<int, int>> q;
        q.push({sx, sy});
        while(!q.empty()){
            int cx = q.front().first, cy = q.front().second; q.pop();
            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(in_area(nx, ny) && maze[nx][ny] != '#' && dis[nx][ny] == INF){
                    dis[nx][ny] = dis[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dis;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
