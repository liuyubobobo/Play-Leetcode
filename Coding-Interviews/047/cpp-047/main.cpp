/// Source : https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/
/// Author : liuyubobobo
/// Time   : 2023-03-07

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
        return dp[R][C];
    }
};


int main() {

    return 0;
}
