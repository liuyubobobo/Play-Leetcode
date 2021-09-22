/// Source : https://leetcode.com/problems/shortest-distance-from-all-buildings/
/// Author : liuyubobobo
/// Time   : 2021-09-22

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(R * C * R * C)
/// Space Complexity: O(R * C * R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    int shortestDistance(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();

        vector<vector<vector<int>>> dis;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == 1)
                    dis.push_back(bfs(grid, i, j));

        int res = INT_MAX;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == 0){
                    int tres = 0;
                    for(int k = 0; k < dis.size(); k ++)
                        if(dis[k][i][j] == INT_MAX){
                            tres = INT_MAX;
                            break;
                        }
                        else tres += dis[k][i][j];
                    res = min(res, tres);
                }
        return res == INT_MAX ? -1 : res;
    }

private:
    vector<vector<int>> bfs(const vector<vector<int>>& grid, int x, int y){

        vector<vector<int>> dis(R, vector<int>(C, INT_MAX));
        queue<int> q;
        q.push(x * C + y);
        dis[x][y] = 0;

        while(!q.empty()){
            int cur = q.front(); q.pop();
            int cx = cur / C, cy = cur % C;

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(0 <= nx && nx < R && 0 <= ny && ny < C && grid[nx][ny] == 0 && dis[nx][ny] == INT_MAX){
                    dis[nx][ny] = 1 + dis[cx][cy];
                    q.push(nx * C + ny);
                }
            }
        }
        return dis;
    }
};


int main() {

    return 0;
}
