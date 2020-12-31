/// Source : https://leetcode.com/problems/surface-area-of-3d-shapes/description/
/// Author : liuyubobobo
/// Time   : 2018-08-25

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(m*n)
/// Space Complexity: O(1)
class Solution {

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

public:
    int surfaceArea(vector<vector<int>>& grid) {

        m = grid.size();
        if(m == 0)
            return 0;
        n = grid[0].size();

        int res = 0;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                if(grid[i][j]){
                    res += 2;
                    for(int k = 0; k < 4; k ++){
                        int newX = i + d[k][0];
                        int newY = j + d[k][1];
                        if(!inArea(newX, newY))
                            res += grid[i][j];
                        else
                            res += max(grid[i][j] - grid[newX][newY], 0);
                    }
                }
            }
        return res;
    }

private:
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    vector<vector<int>> grid1 = {{2}};
    cout << Solution().surfaceArea(grid1) << endl;
    // 10

    vector<vector<int>> grid2 = {{1, 2}, {3, 4}};
    cout << Solution().surfaceArea(grid2) << endl;
    // 34

    vector<vector<int>> grid3 = {{1, 0}, {0, 2}};
    cout << Solution().surfaceArea(grid3) << endl;
    // 16

    vector<vector<int>> grid4 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << Solution().surfaceArea(grid4) << endl;
    // 32

    vector<vector<int>> grid5 = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
    cout << Solution().surfaceArea(grid5) << endl;
    // 46

    return 0;
}