/// Source : https://leetcode.com/problems/shortest-path-to-get-food/
/// Author : liuyubobobo
/// Time   : 2021-01-22

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int getFood(vector<vector<char>>& grid) {

        int R = grid.size(), C = grid[0].size(), s;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == '*') s = i * C + j;

        vector<vector<int>> dis(R, vector<int>(C, -1));
        queue<int> q;
        q.push(s);
        dis[s / C][s % C] = 0;
        while(!q.empty()){

            int cur = q.front(); q.pop();
            int curx = cur / C, cury = cur % C;
            if(grid[curx][cury] == '#') return dis[curx][cury];

            for(int d = 0; d < 4; d ++){
                int nextx = curx + dirs[d][0], nexty = cury + dirs[d][1];
                if(nextx >= 0 && nextx < R && nexty >= 0 && nexty < C &&
                   grid[nextx][nexty] != 'X' && dis[nextx][nexty] == -1){

                    dis[nextx][nexty] = dis[curx][cury] + 1;
                    q.push(nextx * C + nexty);
                }
            }
        }
        return -1;
    }
};


int main() {

    return 0;
}
