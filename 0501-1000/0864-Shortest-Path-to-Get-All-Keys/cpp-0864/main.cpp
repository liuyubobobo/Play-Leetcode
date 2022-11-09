/// Source : https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
/// Author : liuyubobobo
/// Time   : 2018-07-09
/// Updated: 2022-11-09

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// BFS
/// Time Complexity: O(R * C * (2 ^ key_cnt))
/// Space Complexity:O(R * C * (2 ^ key_cnt))
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int shortestPathAllKeys(vector<string>& grid) {

        int R = grid.size(), C = grid[0].size();

        int sx = -1, sy = -1, key_cnt = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(grid[i][j] == '@'){
                    sx = i, sy = j;
                }
                else if(islower(grid[i][j])){
                    key_cnt ++;
                }
            }
        assert(sx != -1 && sy != -1);

        vector<vector<int>> dis(R * C, vector<int>((1 << key_cnt), -1));
        dis[sx * C + sy][0] = 0;
        queue<pair<int, int>> q;
        q.push({sx * C + sy, 0});
        while(!q.empty()){
            int cpos = q.front().first, key_state = q.front().second;
            int cx = cpos / C, cy = cpos % C;
            q.pop();

            if(key_state == (1 << key_cnt) - 1) return dis[cpos][key_state];

            for(int d = 0; d < 4; d ++){
                int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                if(!in_area(R, C, nx, ny) || grid[nx][ny] == '#') continue;

                if(isupper(grid[nx][ny]) && ((1 << (grid[nx][ny] - 'A')) & key_state) == 0)
                    continue;

                int npos = nx * C + ny;
                int next_key_state = key_state;
                if(islower(grid[nx][ny])) next_key_state |= (1 << (grid[nx][ny] - 'a'));

                if(dis[npos][next_key_state] != -1) continue;

                dis[npos][next_key_state] = dis[cpos][key_state] + 1;
                q.push({npos, next_key_state});
            }
        }
        return -1;
    }

private:
    bool in_area(int R, int C, int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    vector<string> grid1 = {"@.a.#",
                            "###.#",
                            "b.A.B"};
    cout << Solution().shortestPathAllKeys(grid1) << endl;
    // 8

    vector<string> grid2 = {"@..aA",
                            "..B#.",
                            "....b"};
    cout << Solution().shortestPathAllKeys(grid2) << endl;
    // 6

    vector<string> grid3 = {"@Aa"};
    cout << Solution().shortestPathAllKeys(grid3) << endl;
    // -1

    return 0;
}