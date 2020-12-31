/// Source : https://leetcode.com/problems/stone-game-vii/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

public:
    int stoneGameVII(vector<int>& stones) {

        int n = stones.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + stones[i];

        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, 0)));

        for(int sz = 2; sz <= n; sz ++)
            for(int l = 0; l + sz - 1 < n; l ++){

                int r = l + sz - 1;
                dp[0][l][r] = max(presum[r + 1] - presum[l + 1] + dp[1][l + 1][r],
                                  presum[r] - presum[l] + dp[1][l][r - 1]);
                dp[1][l][r] = min(- (presum[r + 1] - presum[l + 1]) + dp[0][l + 1][r],
                                  - (presum[r] - presum[l]) + dp[0][l][r - 1]);
            }
        return dp[0][0][n - 1];
    }
};


int main() {

    vector<int> stones1 = {5,3,1,4,2};
    cout << Solution().stoneGameVII(stones1) << endl;
    // 6

    vector<int> stones2 = {7,90,5,1,100,10,10,2};
    cout << Solution().stoneGameVII(stones2) << endl;
    // 122

    return 0;
}
