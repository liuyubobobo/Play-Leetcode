/// Source : https://leetcode-cn.com/problems/UlBDOe/
/// Author : liuyubobobo
/// Time   : 2021-02-05

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int minimumOperations(string leaves) {

        int n = leaves.size();
        vector<vector<int>> dp(3, vector<int>(n));

        // r
        dp[0][0] = (leaves[0] != 'r');
        for(int i = 1; i < n; i ++)
            dp[0][i] = dp[0][i - 1] + (leaves[i] != 'r');

        // ry
        dp[1][1] = (leaves[1] != 'y') + dp[0][0];
        for(int i = 2; i < n; i ++)
            dp[1][i] = (leaves[i] != 'y') + min(dp[1][i - 1], dp[0][i - 1]);

        // ryr
        dp[2][2] = (leaves[2] != 'r') + dp[1][1];
        for(int i = 3; i < n; i ++)
            dp[2][i] = (leaves[i] != 'r') + min(dp[2][i - 1], dp[1][i - 1]);

        return dp[2].back();
    }
};


int main() {

    cout << Solution().minimumOperations("rrryyyrryyyrr") << endl;
    // 2

    cout << Solution().minimumOperations("ryr") << endl;
    // 0

    return 0;
}
