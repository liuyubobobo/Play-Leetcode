/// Source : https://leetcode.com/problems/paint-house-iii/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming + Rolling Array
/// Time Complexity: O(m^2 * n^2)
/// Space Complexity: O(m * n)
class Solution {

private:
    const int INF = 1e7;

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

        if(!houses[0]) for(int color = 1; color <= n; color ++) dp[color][1] = cost[0][color - 1];
        else dp[houses[0]][1] = 0;

        for(int index = 1; index < m; index ++){

            vector<vector<int>> tdp(n + 1, vector<int>(m + 1, INF));

            for(int color = 1; color <= n; color ++)
                if(!houses[index] || houses[index] == color)
                    for(int precolor = 1; precolor <= n; precolor ++)
                        for(int k = 1; k <= target; k ++)
                            tdp[color][k] = min(tdp[color][k],
                                                (houses[index] ? 0 : cost[index][color - 1]) + dp[precolor][k - (precolor != color)]);
            dp = tdp;
        }

        int res = INF;
        for(int color = 1; color <= n; color ++) res = min(res, dp[color][target]);
        return res == INF ? -1 : res;
    }
};


int main() {

    return 0;
}
