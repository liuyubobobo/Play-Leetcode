/// Source : https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/
/// Author : liuyubobobo
/// Time   : 2020-02-18

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(m * n * m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    int R, C, M;
    const int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

public:
    int minPushBox(vector<vector<char>>& grid) {

        R = grid.size(), C = grid[0].size(), M = R * C;
        int start = -1, end = -1, box = -1;
        for(int i = 0; i < R * C; i ++)
            if(grid[i / C][i % C] == 'S')
                start = i, grid[i / C][i % C] = '.';
            else if(grid[i / C][i % C] == 'B')
                box = i, grid[i / C][i % C] = '.';
            else if(grid[i / C][i % C] == 'T')
                end = i, grid[i / C][i % C] = '.';
        return bfs(grid, start, end, box);
    }

private:
    int bfs(vector<vector<char>>& grid, int start, int end, int box){

        int start_hashcode = start * M + box;
        queue <int> q;
        q.push(start_hashcode);

        map<int, int> visited;
        visited[start_hashcode] = 0;

        while(!q.empty()){

            int curhash = q.front();
            q.pop();

            int s = curhash / M, b = curhash % M, step = visited[curhash];

            if(b == end) return step;

            int bx = b / C, by = b % C;
            for(int d = 0; d < 4; d ++){
                int nextx = bx + dirs[d][0], nexty = by + dirs[d][1];
                if(in_area(nextx, nexty) && grid[nextx][nexty] != '#' && ok(grid, s, nextx * C + nexty, b)){

                    int nextbx = bx + dirs[(d + 2) % 4][0], nextby = by + dirs[(d + 2) % 4][1];
                    if(in_area(nextbx, nextby) && grid[nextbx][nextby] != '#'){
                        int nexthash = (nextx * C + nexty) * M + (nextbx * C + nextby);
                        if(!visited.count(nexthash)) {
                            q.push(nexthash);
                            visited[nexthash] = step + 1;
                        }
                    }
                }
            }
        }
        return -1;
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }

    bool ok(vector<vector<char>>& grid, int start, int end, int box){

        vector<bool> visited(R * C, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){

            int cur = q.front();
            q.pop();

            if(cur == end) return true;

            int curx = cur / C, cury = cur % C;
            for(int d = 0; d < 4; d ++){
                int nextx = curx + dirs[d][0], nexty = cury + dirs[d][1];
                if(in_area(nextx, nexty) && grid[nextx][nexty] == '.'
                   && nextx * C + nexty != box && !visited[nextx * C + nexty]){
                    q.push(nextx * C + nexty);
                    visited[nextx * C + nexty] = true;
                }
            }
        }
        return false;
    }
};


int main() {

    vector<vector<char>> grid1 = {
            {'#','#','#','#','#','#'},
            {'#','T','#','#','#','#'},
            {'#','.','.','B','.','#'},
            {'#','.','#','#','.','#'},
            {'#','.','.','.','S','#'},
            {'#','#','#','#','#','#'}
    };
    cout << Solution().minPushBox(grid1) << endl;
    // 3

    vector<vector<char>> grid2 = {
            {'#','#','#','#','#','#'},
            {'#','T','.','.','#','#'},
            {'#','.','#','B','.','#'},
            {'#','.','.','.','.','#'},
            {'#','.','.','.','S','#'},
            {'#','#','#','#','#','#'}
    };
    cout << Solution().minPushBox(grid2) << endl;
    // 5

    vector<vector<char>> grid3 = {
            {'.','.','#','.','.','.','.','.','.','.'},
            {'.','#','.','#','B','#','.','#','.','.'},
            {'.','#','.','.','.','.','.','.','T','.'},
            {'#','.','.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.','.','#'},
            {'.','.','.','.','.','.','.','.','#','.'},
            {'.','.','.','#','.','.','#','#','.','.'},
            {'.','.','.','.','#','.','.','#','.','.'},
            {'.','#','.','S','.','.','.','.','.','.'},
            {'#','.','.','#','.','.','.','.','.','#'}
    };
    cout << Solution().minPushBox(grid3) << endl;
    // 5

    return 0;
}