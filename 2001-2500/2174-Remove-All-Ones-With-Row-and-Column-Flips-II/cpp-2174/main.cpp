/// Source : https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips-ii/
/// Author : liuyubobobo
/// Time   : 2022-02-18

#include <iostream>
#include <vector>

using namespace std;


/// State-Comppression Memoization
/// Time Complexity: O(R * C * 2^(R * C))
/// Space Complexity: O(2^(R * C))
class Solution {

public:
    int removeOnes(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        vector<int> dp(1 << (R * C), -1);
        return dfs(R, C, grid, dp);
    }

private:
    int dfs(int R, int C, const vector<vector<int>> grid, vector<int>& dp){

        int state = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j]) state |= (1 << (i * C + j));

        if(state == 0) return 0;
        if(dp[state] != -1) return dp[state];

        int res = INT_MAX;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j]){
                    vector<vector<int>> t = grid;
                    for(int k = 0; k < R; k ++) t[k][j] = 0;
                    for(int k = 0; k < C; k ++) t[i][k] = 0;
                    res = min(res, 1 + dfs(R, C, t, dp));
                }
        return dp[state] = res;
    }
};


int main() {

    return 0;
}
