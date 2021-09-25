/// Source : https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(R * C * K)
/// Space Complexity: O(R * C * K)
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int R, C;

public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        R = grid.size(), C = grid[0].size();

        vector<vector<int>> dis(R * C, vector<int>(k + 1, -1));
        dis[0][k] = 0;
        queue<pair<int, int>> q;
        q.push({0, k});

        while(!q.empty()){
            int cpos = q.front().first, left = q.front().second;
            int cx = cpos / C, cy = cpos % C;
            q.pop();

            if(cpos == R * C - 1) return dis[cpos][left];

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(!in_area(nx, ny)) continue;
                if(left == 0 && grid[nx][ny]) continue;

                int npos = nx * C + ny, nleft = left - grid[nx][ny];
                if(dis[npos][nleft] != -1) continue;

                dis[npos][nleft] = dis[cpos][left] + 1;
                q.push({npos, nleft});
            }
        }
        return -1;
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
