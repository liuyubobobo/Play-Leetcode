/// Source : https://leetcode.com/problems/paint-house/
/// Author : liuyubobobo
/// Time   : 2021-05-04

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        int n = costs.size();

        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0] = costs[0];
        for(int i = 1; i < n; i ++)
            for(int j = 0; j < 3; j ++){
                for(int k = 0; k < 3; k ++)
                    if(k != j) dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i][j]);
            }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};


int main() {

    return 0;
}
