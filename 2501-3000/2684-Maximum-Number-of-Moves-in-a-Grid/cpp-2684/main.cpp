/// Source : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// DP
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> dp(R, vector<int>(C, -1));
        for(int i = 0; i < R; i ++) dp[i][0] = 0;

        for(int j = 0; j + 1 < C; j ++){
            for(int i = 0; i < R; i ++){
                if(dp[i][j] == -1) continue;
                for(int d = -1; d <= 1; d ++){
                    if(i + d < 0 || i + d >= R) continue;
                    if(grid[i + d][j + 1] <= grid[i][j]) continue;
                    dp[i + d][j + 1] = max(dp[i + d][j + 1], dp[i][j] + 1);
                }
            }
        }

        int res = 0;
        for(int i = 0; i < R; i ++) res = max(res, *max_element(dp[i].begin(), dp[i].end()));
        return res;
    }
};


int main() {


    return 0;
}
