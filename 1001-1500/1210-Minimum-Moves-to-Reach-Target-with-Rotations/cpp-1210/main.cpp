/// Source : https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
/// Author : liuyubobobo
/// Time   : 2019-09-28

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


/// BFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[2][2] = {{1, 0}, {0, 1}};
    int R, C;

public:
    int minimumMoves(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();
        unordered_map<int, int> visited;
        visited[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            const int curcode = q.front();
            int cur = curcode;
            q.pop();

            const int d = cur % 10; cur /= 10;
            const int y1 = cur % 1000, x1 = cur / 1000;

            int x2, y2;
            if(d == 0) x2 = x1, y2 = y1 + 1;
            else x2 = x1 + 1, y2 = y1;

            for(int dir = 0; dir < 3; dir ++){

                int nextx1 = -1, nexty1 = -1, nextx2 = -1, nexty2 = -1, nextcode = -1;
                if(dir < 2){
                    nextx1 = x1 + dirs[dir][0], nexty1 = y1 + dirs[dir][1];
                    nextx2 = x2 + dirs[dir][0], nexty2 = y2 + dirs[dir][1];
                    nextcode = nextx1 * 10000 + nexty1 * 10 + d;
                }
                else if(d == 0 && in_area(x1 + 1, y1) && in_area(x1 + 1, y1 + 1)
                        && !grid[x1 + 1][y1] && !grid[x1 + 1][y1 + 1]){
                    nextx1 = x1, nexty1= y1;
                    nextx2 = x1 + 1, nexty2 = y1;
                    nextcode = nextx1 * 10000 + nexty1 * 10 + 1;
                }
                else if(d == 1 && in_area(x1, y1 + 1) && in_area(x1 + 1, y1 + 1)
                        && !grid[x1][y1 + 1] && !grid[x1 + 1][y1 + 1]){
                    nextx1 = x1, nexty1 = y1;
                    nextx2 = x1, nexty2 = y1 + 1;
                    nextcode = nextx1 * 10000 + nexty1 * 10 + 0;
                }

                if(in_area(nextx1, nexty1) && in_area(nextx2, nexty2)
                   && !grid[nextx1][nexty1] && !grid[nextx2][nexty2] && !visited.count(nextcode)){

                    visited[nextcode] = visited[curcode] + 1;
                    q.push(nextcode);

                    if(nextx1 == R - 1 && nexty1 == C - 2 && nextx2 == R - 1 && nexty2 == C - 1)
                        return visited[nextcode];
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

    vector<vector<int>> grid1 = {
            {0,0,0,0,0,1},
            {1,1,0,0,1,0},
            {0,0,0,0,1,1},
            {0,0,1,0,1,0},
            {0,1,1,0,0,0},
            {0,1,1,0,0,0}
    };
    cout << Solution().minimumMoves(grid1) << endl;
    // 11

    vector<vector<int>> grid2 = {
            {0,0,1,1,1,1},
            {0,0,0,0,1,1},
            {1,1,0,0,0,1},
            {1,1,1,0,0,1},
            {1,1,1,0,0,1},
            {1,1,1,0,0,0}
    };
    cout << Solution().minimumMoves(grid2) << endl;
    // 9

    vector<vector<int>> grid3 = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 0, 1, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    cout << Solution().minimumMoves(grid3) << endl;
    // -1

    return 0;
}