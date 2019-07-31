/// Source : https://leetcode.com/problems/largest-1-bordered-square/
/// Author : liuyubobobo
/// Time   : 2019-07-27

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {

        int r = grid.size(), c = grid[0].size();

        vector<vector<int>> row(r, vector<int>(c + 1, 0));
        for(int i = 0; i < r; i ++)
            for(int j = 0; j < c; j ++)
                row[i][j + 1] = row[i][j] + grid[i][j];
//        for(int i = 0; i < r; i ++) {
//            for (int j = 0; j <= c; j++)
//                cout << row[i][j] << " ";
//            cout << endl;
//        }
//        cout << endl;

        vector<vector<int>> col(r + 1, vector<int>(c, 0));
        for(int j = 0; j < c; j ++)
            for(int i = 0; i < r; i ++)
                col[i + 1][j] = col[i][j] + grid[i][j];
//        for(int i = 0; i <= r; i ++) {
//            for (int j = 0; j < c; j++)
//                cout << col[i][j] << " ";
//            cout << endl;
//        }

        int res = 0;
        for(int sx = 0; sx < r; sx ++)
            for(int sy = 0; sy < c; sy ++)
                for(int sz = 1; sx + sz <= r && sy + sz <= c; sz ++)
                    if(row[sx][sy + sz] - row[sx][sy] == sz &&
                       row[sx + sz - 1][sy + sz] - row[sx + sz - 1][sy] == sz &&
                       col[sx + sz][sy] - col[sx][sy] == sz &&
                       col[sx + sz][sy + sz - 1] - col[sx][sy + sz - 1] == sz)
                        res = max(res, sz * sz);
        return res;
    }
};


int main() {

    vector<vector<int>> grid1 = {{1,1,1},{1,0,1},{1,1,1}};
    cout << Solution().largest1BorderedSquare(grid1) << endl;
    // 9

    vector<vector<int>> grid2 = {{1,1,0,0}};
    cout << Solution().largest1BorderedSquare(grid2) << endl;
    // 1

    return 0;
}