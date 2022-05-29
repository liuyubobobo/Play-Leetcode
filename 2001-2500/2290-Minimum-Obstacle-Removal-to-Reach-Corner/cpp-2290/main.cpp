/// Source : https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
/// Author : liuyubobobo
/// Time   : 2022-05-29

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// 0-1 BFS
/// Time Complexity: O(n * m)
/// Space Complexity: O(n * m)
class Solution {

private:
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int R, C;

public:
    int minimumObstacles(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();

        vector<vector<pair<int, int>>> g(R * C);
        for(int x = 0; x < R; x ++)
            for(int y = 0; y < C; y ++){
                int u = x * C + y;
                for(int d = 0; d < 4; d ++){
                    int nx = x + dirs[d][0], ny = y + dirs[d][1];
                    if(in_area(nx, ny)){
                        int v = nx * C + ny;
                        if(grid[nx][ny])
                            g[u].push_back({v, 1});
                        else
                            g[u].push_back({v, 0});
                    }
                }
            }

        vector<int> dis(R * C, INT_MAX / 2);
        vector<bool> visited(R * C, false);
        deque<int> q;
        q.push_back(0);
        dis[0] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop_front();
            if(visited[u]) continue;

            visited[u] = true;
            for(const pair<int, int>& p: g[u]){
                int v = p.first, w = p.second;
                if(!visited[v] && dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    if(w) q.push_back(v);
                    else q.push_front(v);
                }
            }
        }
        return dis[R * C - 1];
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
