/// Source : https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
/// Author : liuyubobobo
/// Time   : 2020-09-19

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int maxProductPath(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        vector<vector<long long>> biggest(R, vector<long long>(C, 0ll));
        vector<vector<long long>> smallest(R, vector<long long>(C, 0ll));

        smallest[0][0] = biggest[0][0] = grid[0][0];
        for(int i = 1; i < R; i ++)
            biggest[i][0] = smallest[i][0] = grid[i][0] * smallest[i - 1][0];
        for(int j = 1; j < C; j ++)
            biggest[0][j] = smallest[0][j] = grid[0][j] * smallest[0][j - 1];

        for(int i = 1; i < R; i ++)
            for(int j = 1; j < C; j ++){
                smallest[i][j] = min(min(grid[i][j] * smallest[i - 1][j], grid[i][j] * smallest[i][j - 1]),
                                     min(grid[i][j] * biggest[i - 1][j], grid[i][j] * biggest[i][j - 1]));
                biggest[i][j] = max(max(grid[i][j] * smallest[i - 1][j], grid[i][j] * smallest[i][j - 1]),
                                    max(grid[i][j] * biggest[i - 1][j], grid[i][j] * biggest[i][j - 1]));
            }

        if(biggest[R - 1][C - 1] >= 0) return biggest[R - 1][C - 1] % MOD;
        return -1;
    }
};


int main() {

    vector<vector<int>> g1 = {
            {-1,-2,-3},
            {-2,-3,-3},
            {-3,-3,-2}
    };
    cout << Solution().maxProductPath(g1) << endl;
    // -1

    vector<vector<int>> g2 = {
            {1,-2,1},
            {1,-2,1},
            {3,-4,1}
    };
    cout << Solution().maxProductPath(g2) << endl;
    // 8

    vector<vector<int>> g3 = {
            {1,3},
            {0,-4}
    };
    cout << Solution().maxProductPath(g3) << endl;
    // 0

    vector<vector<int>> g4 = {
            { 1, 4,4,0},
                {-2, 0,0,1},
            {1,-1,1,1}
    };
    cout << Solution().maxProductPath(g4) << endl;
    // 2

    return 0;
}