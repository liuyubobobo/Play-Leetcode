/// Source : https://leetcode.com/problems/shortest-path-in-a-hidden-grid/
/// Author : liuyubobobo
/// Time   : 2021-03-05

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cassert>

using namespace std;


// This is the gridMaster's API interface.
// You should not implement it, or speculate about its implementation
class GridMaster {

public:
    bool canMove(char direction);
    void move(char direction);
    bool isTarget();
};


/// DFS and BFS
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    const map<char, pair<int, int>> dirs = {
            {'U', {-1, 0}},
            {'D', {1, 0}},
            {'L', {0, -1}},
            {'R', {0, 1}}
    };
    const map<char, char> rd = {
            {'U', 'D'},
            {'D', 'U'},
            {'L', 'R'},
            {'R', 'L'}
    };
    int startx = 501, starty = 501, endx, endy;

public:
    int findShortestPath(GridMaster& master) {

        startx = 501, starty = 501, endx = -1, endy = -1;
        vector<vector<int>> grid(1003, vector<int>(1003, -1));
        dfs(grid, startx, starty, master);

//         cout << "end : " << endx << " " << endy << endl;

        if(endx == -1){
            assert(endy == -1);
            return -1;
        }

        return bfs(grid, startx, starty, endx, endy);
    }

private:
    int bfs(const vector<vector<int>>& grid, int sx, int sy, int tx, int ty){

        vector<vector<int>> dis(1003, vector<int>(1003, -1));
        dis[sx][sy] = 0;

        queue<pair<int, int>> q;
        q.push({sx, sy});

        const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int curx = q.front().first, cury = q.front().second;
            q.pop();

            if(curx == tx && cury == ty) return dis[curx][cury];

            for(int d = 0; d < 4; d ++){
                int nextx = curx + dirs[d][0], nexty = cury + dirs[d][1];
                if(grid[nextx][nexty] == 0 && dis[nextx][nexty] == -1){
                    dis[nextx][nexty] = 1 + dis[curx][cury];
                    q.push({nextx, nexty});
                }
            }
        }
        assert(false);
        return -1;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, GridMaster& master){

        if(master.isTarget()) endx = x, endy = y;

        for(const pair<char, pair<int, int>>& p: dirs){
            char d = p.first;
            int dx = p.second.first, dy = p.second.second;
            int nextx = x + dx, nexty = y + dy;

            if(grid[nextx][nexty] == -1){
                if(master.canMove(d)){
                    grid[nextx][nexty] = 0;
                    master.move(d);
                    dfs(grid, nextx, nexty, master);
                    master.move(rd.at(d));
                }
                else{
                    grid[nextx][nexty] = 1;
                }
            }
        }
    }
};


int main() {

    return 0;
}
