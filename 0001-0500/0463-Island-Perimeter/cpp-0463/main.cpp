/// Source : https://leetcode.com/problems/island-perimeter/
/// Author : liuyubobobo
/// Time   : 2021-10-03

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(R * C)
/// Space Complexity: O(1)
class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int R, C;

public:
    int islandPerimeter(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();
        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(grid[i][j] == 0) continue;
                for(int d = 0; d < 4; d ++){
                    int nx = i + dirs[d][0], ny = j + dirs[d][1];
                    if(!in_area(nx, ny) || grid[nx][ny] == 0) res ++;
                }
            }
        return res;
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    return 0;
}
