/// Source : https://leetcode.com/problems/unique-paths/
/// Author : liuyubobobo
/// Time   : 2019-04-02

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));
        return dfs(m - 1, n - 1, dp);
    }

private:
    int dfs(int x, int y, vector<vector<int>>& dp){

        if(x == 0 || y == 0) return 1;
        if(dp[x][y]) return dp[x][y];

        int res = dfs(x - 1, y, dp) + dfs(x, y - 1, dp);
        return dp[x][y] = res;
    }
};


int main() {

    return 0;
}