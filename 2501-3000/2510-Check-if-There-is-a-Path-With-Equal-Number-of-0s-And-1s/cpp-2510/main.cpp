/// Source : https://leetcode.com/problems/check-if-there-is-a-path-with-equal-number-of-0s-and-1s/description/
/// Author : liuyubobobo
/// Time   : 2022-12-22

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n * m * (n + m))
/// Space Complexity: O(n * m * (n + m))
class Solution {
public:
    bool isThereAPath(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        if((n + m - 1) & 1) return false;

        const int OFFSET = n + m - 1;
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(m, vector<bool>(2 * OFFSET + 1, false)));

        // zero - one
        dp[0][0][(grid[0][0] == 0 ? 1 : -1) + OFFSET] = true;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                for(int value = -OFFSET; value <= OFFSET; value ++){
                    if(!dp[i][j][ value + OFFSET]) continue;
                    if(i + 1 < n && value + (grid[i + 1][j] ? -1 : 1) <= OFFSET)
                        dp[i + 1][j][value + (grid[i + 1][j] ? -1 : 1) + OFFSET] = true;
                    if(j + 1 < m && value + (grid[i][j + 1] ? -1 : 1) <= OFFSET)
                        dp[i][j + 1][value + (grid[i][j + 1] ? -1 : 1) + OFFSET] = true;
                }
        return dp[n - 1][m - 1][OFFSET];
    }
};


int main() {

    return 0;
}
