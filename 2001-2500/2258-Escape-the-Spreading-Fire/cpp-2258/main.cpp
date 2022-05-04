/// Source : https://leetcode.com/problems/escape-the-spreading-fire/
/// Author : liuyubobobo
/// Time   : 2022-05-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Binary Search
/// Time Complexity: O(m * n * log(m * n))
/// Space Complexity: O(m * n)
class Solution {

private:
    const int dirs[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int R, C;

public:
    int maximumMinutes(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();

        vector<vector<int>> fire_time(R, vector<int>(C, 2e9));
        queue<int> q;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == 1){
                    fire_time[i][j] = 0;
                    q.push(i * C + j);
                }

        while(!q.empty()){
            int cx = q.front() / C, cy = q.front() % C, cur_time = fire_time[cx][cy];
            q.pop();

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(in_area(nx, ny) && grid[nx][ny] != 2 && fire_time[nx][ny] == 2e9){
                    fire_time[nx][ny] = cur_time + 1;
                    q.push(nx * C + ny);
                }
            }
        }

//        for(const vector<int>& row: fire_time){
//            for(int e: row) cout << e << ' ';
//            cout << '\n';
//        }

        int l = -1, r = 1e9;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(ok(grid, fire_time, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(const vector<vector<int>>& grid, const vector<vector<int>>& fire_time, int t){

        if(grid[0][0] == 2 || t > fire_time[0][0]) return false;

        vector<vector<int>> visited(R, vector<int>(C, -1));
        queue<int> q;
        q.push(0);
        visited[0][0] = t;

        while(!q.empty()){
            int cx = q.front() / C, cy = q.front() % C, cur_t = visited[cx][cy];
            q.pop();

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(in_area(nx, ny) && grid[nx][ny] != 2 && visited[nx][ny] == -1){

                    if(cur_t + 1 > fire_time[nx][ny]) continue;
                    if(nx == R - 1 && ny == C - 1) return true;

                    if(cur_t + 1 < fire_time[nx][ny]){
                        visited[nx][ny] = cur_t + 1;
                        q.push(nx * C + ny);
                    }
                }
            }
        }
        return false;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<vector<int>> grid1 = {
            {0,2,0,0,0,0,0},
            {0,0,0,2,2,1,0},
            {0,2,0,0,1,2,0},
            {0,0,2,2,2,0,2},
            {0,0,0,0,0,0,0}
    };
    cout << Solution().maximumMinutes(grid1) << '\n';
    // 3

    vector<vector<int>> grid2 = {
            {0,2,0,0,1},
            {0,2,0,2,2},
            {0,2,0,0,0},
            {0,0,2,2,0},
            {0,0,0,0,0}
    };
    cout << Solution().maximumMinutes(grid2) << '\n';
    // 0

    return 0;
}
