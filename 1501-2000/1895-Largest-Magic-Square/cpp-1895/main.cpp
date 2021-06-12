/// Source : https://leetcode.com/problems/largest-magic-square/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Brute Force
/// Time Complexity: O(m * n * min(m, n))
/// Space Complexity: O(m * n)
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> presum_row(m + 2, vector<int>(n + 2, 0));
        vector<vector<int>> presum_col(m + 2, vector<int>(n + 2, 0));
        vector<vector<int>> presum_dia1(m + 2, vector<int>(n + 2, 0));
        vector<vector<int>> presum_dia2(m + 2, vector<int>(n + 2, 0));
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                presum_row[i + 1][j + 1] = presum_row[i + 1][j] + grid[i][j];
                presum_col[i + 1][j + 1] = presum_col[i][j + 1] + grid[i][j];
                presum_dia1[i + 1][j + 1] = presum_dia1[i][j] + grid[i][j];
                presum_dia2[i + 1][j + 1] = presum_dia2[i][j + 2] + grid[i][j];
            }

        for(int k = max(m, n); k >= 2; k --)
            for(int i = 0; i < m && i + k <= m; i ++)
                for(int j = 0; j < n && j + k <= n; j ++){
                    if(ok(grid, i, j, k, presum_row, presum_col, presum_dia1, presum_dia2))
                        return k;
                }
        return 1;
    }

private:
    bool ok(const vector<vector<int>>& grid, int x, int y, int sz,
            const vector<vector<int>>& presum_row, const vector<vector<int>>& presum_col,
            const vector<vector<int>>& presum_dia1, const vector<vector<int>>& presum_dia2){

        int sum = presum_row[x + 1][y + sz] - presum_row[x + 1][y];
        for(int i = x; i < x + sz; i ++)
            if(presum_row[i + 1][y + sz] - presum_row[i + 1][y] != sum)
                return false;

        for(int j = y; j < y + sz; j ++)
            if(presum_col[x + sz][j + 1] - presum_col[x][j + 1] != sum)
                return false;

        if(presum_dia1[x + sz][y + sz] - presum_dia1[x][y] != sum)
            return false;

        if(presum_dia2[x + sz][y + 1] - presum_dia2[x][y + sz + 1] != sum)
            return false;

        return true;
    }
};


int main() {

    return 0;
}
