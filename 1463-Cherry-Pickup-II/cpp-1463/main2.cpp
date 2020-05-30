/// Source : https://leetcode.com/problems/cherry-pickup-ii/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Memory Search with State Compression
/// Time Complexity: O(C^2 * R)
/// Space Complexity: O(C^2 * R)
class Solution {

private:
    int R, C;

public:
    int cherryPickup(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();
        vector<int> dp(R * 10000 + C * 100 + C, -1);
        return dfs(grid, 0, 0, C - 1, dp);
    }

private:
    int dfs(const vector<vector<int>>& grid, int r, int a, int b,
            vector<int>& dp){

        if(r == R) return 0;
        if(dp[r * 10000 + a * 100 + b] != -1) return dp[r * 10000 + a * 100 + b];

        int cur = a == b ? grid[r][a] : grid[r][a] + grid[r][b];
        int res = 0;
        for(int i = -1; i <= 1; i ++)
            if(a + i >= 0 && a + i < C)
                for(int j = -1; j <= 1; j ++)
                    if(b + j >= 0 && b + j < C)
                        res = max(res, cur + dfs(grid, r + 1, a + i, b + j, dp));
        return dp[r * 10000 + a * 100 + b] = res;
    }
};


int main() {

    vector<vector<int>> g1 = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << Solution().cherryPickup(g1) << endl;
    // 24

    vector<vector<int>> g2 = {{1,0,0,0,0,0,1},{2,0,0,0,0,3,0},{2,0,9,0,0,0,0},{0,3,0,5,4,0,0},{1,0,2,3,0,0,6}};
    cout << Solution().cherryPickup(g2) << endl;
    // 28

    vector<vector<int>> g3 = {{1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3}};
    cout << Solution().cherryPickup(g3) << endl;
    // 22

    vector<vector<int>> g4 = {{1,1},{1,1}};
    cout << Solution().cherryPickup(g4) << endl;
    // 4

    return 0;
}
