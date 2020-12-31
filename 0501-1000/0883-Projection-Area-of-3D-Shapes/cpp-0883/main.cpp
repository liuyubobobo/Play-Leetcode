/// Source : https://leetcode.com/problems/projection-area-of-3d-shapes/description/
/// Author : liuyubobobo
/// Time   : 2018-08-04
#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(m*n)
/// Space Complexity: O(1)
class Solution {

public:
    int projectionArea(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int res = n * m;
        for(int i = 0; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(grid[i][j] == 0)
                    res --;

        for(const vector<int>& line: grid)
            res += *max_element(line.begin(), line.end());

        for(int j = 0; j < m ; j ++){
            int v = grid[0][j];
            for(int i = 1 ; i < n ; i ++)
                v = max(v, grid[i][j]);
            res += v;
        }

        return res;
    }
};


int main() {

    vector<vector<int>> grid1 = {{2}};
    cout << Solution().projectionArea(grid1) << endl;
    // 5

    vector<vector<int>> grid2 = {{1, 2}, {3, 4}};
    cout << Solution().projectionArea(grid2) << endl;
    // 17

    vector<vector<int>> grid3 = {{1, 0}, {0, 2}};
    cout << Solution().projectionArea(grid3) << endl;
    // 8

    vector<vector<int>> grid4 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << Solution().projectionArea(grid4) << endl;
    // 14

    vector<vector<int>> grid5 = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
    cout << Solution().projectionArea(grid5) << endl;
    // 21

    return 0;
}