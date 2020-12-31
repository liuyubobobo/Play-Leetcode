/// Source : https://leetcode.com/problems/maximal-square/
/// Author : liuyubobobo
/// Time   : 2020-01-06

#include <iostream>
#include <vector>

using namespace  std;


/// Memory Search
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.size() == 0) return 0;

        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, -1));
        int res = 0;
        for(int i = matrix.size() - 1; i >= 0; i --)
            for(int j = matrix[i].size() - 1; j >= 0; j --)
                res = max(res, dfs(matrix, i, j, dp));
        return res * res;
    }

private:
    int dfs(const vector<vector<char>>& matrix, int x, int y,
            vector<vector<int>>& dp){

        if(x == 0 || y == 0) return dp[x][y] = matrix[x][y] == '1' ? 1 : 0;
        if(matrix[x][y] == '0') return dp[x][y] = 0;
        if(dp[x][y] != -1) return dp[x][y];

        int res = min(min(dfs(matrix, x - 1, y, dp), dfs(matrix, x, y - 1, dp)),
                      dfs(matrix, x - 1, y - 1, dp)) + 1;
        return dp[x][y] = res;
    }
};


int main() {

    return 0;
}
