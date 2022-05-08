/// Source : https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
/// Author : liuyubobobo
/// Time   : 2022-05-07

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(R * C * (R + C - 1) / 2)
/// Space Complexity: O(R * C * (R + C - 1) / 2)
class Solution {

private:
    int R, C, L;

public:
    bool hasValidPath(vector<vector<char>>& grid) {

        R = grid.size(), C = grid[0].size();
        L = R + C - 1;
        if(L % 2) return false;

        vector<vector<vector<int>>> dp(R, vector<vector<int>>(C, vector<int>(L / 2 + 1, -1)));
        return dfs(grid, 0, 0, 0, dp);
    }

private:
    int dfs(const vector<vector<char>>& g, int x, int y, int value,
            vector<vector<vector<int>>>& dp){

        int next_value = value + (g[x][y] == '(' ? 1 : -1);
        if(next_value < 0 || next_value > L / 2) return false;
        if(x == R - 1 && y == C - 1) return next_value == 0;

        if(dp[x][y][value] != -1) return dp[x][y][value];

        int res = 0;
        if(in_area(x + 1, y) && dfs(g, x + 1, y, next_value, dp))
            res = 1;
        if(!res && in_area(x, y + 1) && dfs(g, x, y + 1, next_value, dp))
            res = 1;
        return dp[x][y][value] = res;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
