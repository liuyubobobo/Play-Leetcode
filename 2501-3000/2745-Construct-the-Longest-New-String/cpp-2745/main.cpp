/// Source : https://leetcode.com/problems/construct-the-longest-new-string/description/
/// Author : liuyubobobo
/// Time   : 2023-06-25

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(x * y * z)
/// Space Complexity: O(x * y * z)
class Solution {
public:
    int longestString(int x, int y, int z) {

        vector<vector<vector<vector<int>>>> dp(3, vector<vector<vector<int>>>(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, -1))));
        return dfs(0, x, y, z, dp);
    }

private:
    int dfs(int pre, int x, int y, int z, vector<vector<vector<vector<int>>>>& dp){

        if(dp[pre][x][y][z] != -1) return dp[pre][x][y][z];
        int res = 0;
        if(x && pre != 1) res = max(res, 2 + dfs(1, x - 1, y, z, dp));
        if(y && pre != 2) res = max(res, 2 + dfs(2, x, y - 1, z, dp));
        if(z && pre != 1) res = max(res, 2 + dfs(2, x, y, z - 1, dp));
        return dp[pre][x][y][z] = res;
    }
};


int main() {

    return 0;
}
