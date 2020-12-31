/// Source : https://leetcode.com/problems/paint-house-iii/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m^2 * n^2)
/// Space Complexity: O(m^2 * n)
class Solution {

private:
    const int INF = 1e7;

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(m + 1, INF)));

        if(!houses[0]) for(int color = 1; color <= n; color ++) dp[0][color][1] = cost[0][color - 1];
        else dp[0][houses[0]][1] = 0;

        for(int index = 1; index < m; index ++)
            for(int color = 1; color <= n; color ++)
                if(!houses[index] || houses[index] == color)
                    for(int precolor = 1; precolor <= n; precolor ++)
                        for(int k = 1; k <= target; k ++)
                            dp[index][color][k] = min(dp[index][color][k],
                                                      (houses[index] ? 0 : cost[index][color - 1]) + dp[index - 1][precolor][k - (precolor != color)]);

        int res = INF;
        for(int color = 1; color <= n; color ++) res = min(res, dp[m - 1][color][target]);
        return res == INF ? -1 : res;
    }
};


int main() {

    return 0;
}
