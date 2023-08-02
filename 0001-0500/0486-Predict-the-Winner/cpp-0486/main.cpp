#include <iostream>
#include <vector>
#include <climits>

using namespace std;


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        int n = nums.size();
        int p1 = 0, p2 = n - 1;

        vector<vector<int>> dp(n, vector<int>(n, INT_MIN / 2));
        return dfs(nums, p1, p2, dp) >= 0;
    }

private:
    int dfs(const vector<int>& nums, int p1, int p2, vector<vector<int>>& dp) {

        if (p1 > p2) return 0;
        if (dp[p1][p2] != INT_MIN / 2) return dp[p1][p2];
        int a = nums[p1] - dfs(nums, p1 + 1, p2, dp);
        int b = nums[p2] - dfs(nums, p1, p2 - 1, dp);
        return dp[p1][p2] = max(a, b);
    }
};
