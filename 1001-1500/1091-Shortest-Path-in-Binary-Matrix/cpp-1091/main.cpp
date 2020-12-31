/// Source : https://leetcode.com/problems/shortest-path-in-binary-matrix/
/// Author : liuyubobobo
/// Time   : 2019-06-15

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(n * m)
/// Space Complexity: O(n * m)
class Solution {

private:
    const int d[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                         {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int n, m;

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0]) return -1;

        n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, -2));

        queue<int> q;
        res[0][0] = 0;
        q.push(0);
        while(!q.empty()){
            int x = q.front() / m;
            int y = q.front() % m;
            q.pop();

            for(int i = 0; i < 8; i ++){
                int newX = x + d[i][0], newY = y + d[i][1];
                if(newX >= 0 && newX < n && newY >= 0 && newY < m &&
                   grid[newX][newY] == 0 && res[newX][newY] == -2){
                    res[newX][newY] = res[x][y] + 1;
                    q.push(newX * m + newY);
                }
            }
        }

//        for(int i = 0; i < n; i ++){
//            for(int j = 0; j < m; j ++)
//                cout << res[i][j] << " ";
//            cout << endl;
//        }
        return res[n - 1][m - 1] + 1;
    }
};


int main() {

    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    cout << Solution().shortestPathBinaryMatrix(grid) << endl;

    return 0;
}