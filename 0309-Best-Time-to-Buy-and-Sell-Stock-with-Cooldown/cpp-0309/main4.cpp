/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
/// Author : liuyubobobo
/// Time   : 2020-05-25

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Using three states every day
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if(n <= 1)
            return 0;

        vector<vector<int>> dp(n, vector<int>(3, 0)); // 0 hold; 1 sell(cooldown); 2 unhold
        dp[0][0] = -prices[0];

        for(int i = 1 ; i < n ; i ++){
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][2] - prices[i]), dp[i - 1][1] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};


int main() {

    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices1) << endl;
    // 3

    return 0;
}