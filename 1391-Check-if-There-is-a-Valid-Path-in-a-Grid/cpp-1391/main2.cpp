/// Source : https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
/// Author : liuyubobobo
/// Time   : 2020-03-21

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    int m, n;
    vector<vector<pair<int, int>>> next = {{{0, 1},{0, -1}},
                                           {{1, 0}, {-1, 0}},
                                           {{1, 0},{0, -1}},
                                           {{1, 0}, {0, 1}},
                                           {{0, -1},{-1, 0}},
                                           {{-1, 0},{0, 1}}};

public:
    bool hasValidPath(vector<vector<int>>& grid) {

        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            if(x == m - 1 && y == n - 1) return true;

            q.pop();

            int v = grid[x][y] - 1;
            int nextx = x + next[v][0].first, nexty = y + next[v][0].second;
            if(in_area(nextx, nexty) && !visited[nextx][nexty] && connected(grid, nextx, nexty, x, y))
                visited[nextx][nexty] = true, q.push(make_pair(nextx, nexty));

            nextx = x + next[v][1].first, nexty = y + next[v][1].second;
            if(in_area(nextx, nexty) && !visited[nextx][nexty] && connected(grid, nextx, nexty, x, y))
                visited[nextx][nexty] = true, q.push(make_pair(nextx, nexty));
        }
        return false;
    }

private:
    bool connected(const vector<vector<int>>& grid, int x1, int y1, int x2, int y2){

        pair<int, int> p = make_pair(x2 - x1, y2 - y1);
        int v = grid[x1][y1] - 1;
        return next[v][0] == p || next[v][1] == p;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    vector<vector<int>> grid1 = {{2,4,3},{6,5,2}};
    cout << Solution().hasValidPath(grid1) << endl;
    // 1

    vector<vector<int>> grid2 = {{1,2,1},{1,2,1}};
    cout << Solution().hasValidPath(grid2) << endl;
    // 0

    vector<vector<int>> grid3 = {{1,1,2}};
    cout << Solution().hasValidPath(grid3) << endl;
    // 0

    vector<vector<int>> grid4 = {{1,1,1,1,1,1,3}};
    cout << Solution().hasValidPath(grid4) << endl;
    // 1

    return 0;
}