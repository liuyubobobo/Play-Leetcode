/// Source : https://leetcode.com/problems/paint-house-ii/
/// Author : liuyubobobo
/// Time   : 2021-05-04

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n*k^2)
/// Space Complexity: O(nk)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {

        int n = costs.size(), k = costs[0].size();

        vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
        dp[0] = costs[0];
        for(int i = 1; i < n; i ++)
            for(int j = 0; j < k; j ++){
                for(int kk = 0; kk < k; kk ++)
                    if(kk != j) dp[i][j] = min(dp[i][j], dp[i - 1][kk] + costs[i][j]);
            }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};


int main() {

    return 0;
}
