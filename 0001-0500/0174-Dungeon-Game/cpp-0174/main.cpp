/// Source : https://leetcode.com/problems/dungeon-game/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int R = dungeon.size(), C = dungeon[0].size();
        vector<vector<int>> dp(R, vector<int>(C));

        dp[R - 1][C - 1] = max(1 - dungeon[R - 1][C - 1], 1);
        for(int j = C - 2; j >= 0; j --)
            dp[R - 1][j] = max(dp[R - 1][j + 1] - dungeon[R - 1][j], 1);

        for(int i = R - 2; i >= 0; i --){
            dp[i][C - 1] = max(dp[i + 1][C - 1] - dungeon[i][C - 1], 1);
            for(int j = C - 2; j >= 0; j --)
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
        }
        return dp[0][0];
    }
};


int main() {

    return 0;
}
