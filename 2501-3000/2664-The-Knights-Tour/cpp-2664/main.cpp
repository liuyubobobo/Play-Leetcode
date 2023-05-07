/// Source : https://leetcode.com/problems/the-knights-tour/description/
/// Author : liuyubobobo
/// Time   : 2023-05-06

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(exp)
/// Space Complexity: O(R * C)
class Solution {

private:
    const int dirs[8][2] = {
            {-2, -1},
            {-2, 1},
            {-1, -2},
            {-1, 2},
            {1, -2},
            {1, 2},
            {2, -1},
            {2, 1}
    };

public:
    vector<vector<int>> tourOfKnight(int R, int C, int r, int c) {

        vector<vector<int>> res(R, vector<int>(C, -1));
        dfs(R, C, r, c, 0, res);
        return res;
    }

    bool dfs(int R, int C, int x, int y, int step, vector<vector<int>>& res) {

        res[x][y] = step;
        if(step == R * C - 1) return true;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && res[nx][ny] == -1) {
                if(dfs(R, C, nx, ny, step + 1, res)) return true;
            }
        }
        res[x][y] = -1;
        return false;
    }
};


int main() {

    return 0;
}
