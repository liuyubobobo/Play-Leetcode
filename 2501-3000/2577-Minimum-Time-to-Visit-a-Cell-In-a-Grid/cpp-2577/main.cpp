/// Source : https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/
/// Author : liuyubobobo
/// Time   : 2023-04-03

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


/// Dij
/// Time Complexity: O(R * C * log(R * C))
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const int INF = INT_MAX / 2;
    int R, C;

public:
    int minimumTime(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();

        bool can_loop = false;
        if(grid[0][1] <= 1 || grid[1][0] <= 1) can_loop = true;

        vector<vector<int>> dis(R, vector<int>(C, INF));
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[0][0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            int d = pq.top().first, cx = pq.top().second / C, cy = pq.top().second % C;
            pq.pop();

            if(visited[cx][cy]) continue;
            visited[cx][cy] = true;

            for(int i = 0; i < 4; i ++){
                int nx = cx + dirs[i][0], ny = cy + dirs[i][1];
                if(in_area(nx, ny) && !visited[nx][ny]){
                    int nd = d + 1;
                    if(can_loop && nd < grid[nx][ny]) nd = grid[nx][ny] + (grid[nx][ny] % 2 != nd % 2);
                    if(nd < grid[nx][ny]) continue;
                    if(nd < dis[nx][ny]){
                        dis[nx][ny] = nd;
                        pq.push({nd, nx * C + ny});
                    }
                }
            }
        }
        return dis[R - 1][C - 1] == INF ? -1 : dis[R - 1][C - 1];
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<vector<int>> grid1 = {
            {0, 1, 3, 2},
            {5, 1, 2, 5},
            {4, 3, 8, 6}
    };
    cout << Solution().minimumTime(grid1) << '\n';
    // 7

    return 0;
}
