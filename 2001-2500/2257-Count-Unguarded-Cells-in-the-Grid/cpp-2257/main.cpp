/// Source : https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
/// Author : liuyubobobo
/// Time   : 2022-05-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Simulation
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int R, C;

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {

        R = m, C = n;

        vector<string> g(R, string(C, '.'));
        for(const vector<int>& guard: guards)
            g[guard[0]][guard[1]] = 'G';
        for(const vector<int>& wall: walls)
            g[wall[0]][wall[1]] = 'W';

        vector<vector<vector<bool>>> seen(2, vector<vector<bool>>(R, vector<bool>(C, false)));
        for(int i = 0; i < R; i ++) {
            for (int j = 0; j < C; j++) {

                if(g[i][j] != '.'){
                    seen[0][i][j] = seen[1][i][j] = true;
                }

                if (g[i][j] != 'G') continue;
                assert(g[i][j] == 'G');
                for (int d = 0; d < 4; d ++) {
                    for (int step = 1;; step ++) {
                        int nx = i + dirs[d][0] * step, ny = j + dirs[d][1] * step;
                        if (!in_area(nx, ny) || g[nx][ny] != '.' || seen[d / 2][nx][ny]) break;
                        seen[d / 2][nx][ny] = true;
                    }
                }
            }
        }

//        for(int i = 0; i < R; i ++) {
//            for (int j = 0; j < C; j++)
//                cout << seen[0][i][j] << ' ';
//            cout << '\n';
//        }cout << '\n';
//
//        for(int i = 0; i < R; i ++) {
//            for (int j = 0; j < C; j++)
//                cout << seen[1][i][j] << ' ';
//            cout << '\n';
//        }cout << '\n';

//        for(int i = 0; i < R; i ++){
//            for(int j = 0; j < C; j ++)
//                cout << (g[i][j] == '.' && !seen[0][i][j] && !seen[1][i][j]) << ' ';
//            cout << '\n';
//        }

        int res = 0;
        for(int i = 0; i < R; i ++)
            for (int j = 0; j < C; j++)
                res += (g[i][j] == '.' && !seen[0][i][j] && !seen[1][i][j]);

        return res;
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<vector<int>> guards1 = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls1 = {{0,1},{2,2},{1,4}};
    cout << Solution().countUnguarded(4, 6, guards1, walls1) << '\n';
    // 7

    return 0;
}
