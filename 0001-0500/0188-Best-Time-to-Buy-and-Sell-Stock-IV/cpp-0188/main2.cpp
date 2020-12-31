#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n*n*k)
/// Space Complexity: O(n*k)
class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {

        if(k >= prices.size()/2)
            return maxProfit(prices);

        // dp[i][j], start from day[i],
        // the most profit to complete at most j transactions.
        vector<vector<int>> dp(prices.size()+1, vector<int>(k+1, 0));

        for(int j = 1 ; j <= k ; j ++){

            for(int i1 = prices.size()-2 ; i1 >= 0 ; i1 --){
                dp[i1][j] = dp[i1][j-1];
                for(int i2 = i1 + 1 ; i2 < prices.size() ; i2 ++){
                    if(prices[i2] - prices[i1] > 0)
                        dp[i1][j] = max(dp[i1][j],
                                        prices[i2] - prices[i1] + dp[i2+1][j-1]);
                    dp[i1][j] = max(dp[i1][j], dp[i2][j]);
                }
            }
        }

        return dp[0][k];
    }

private:
    int maxProfit(const vector<int>& prices){
        int res = 0;
        for(int i = 1 ; i < prices.size() ; i ++)
            if(prices[i] > prices[i-1])
                res += (prices[i] - prices[i-1]);
        return res;
    }
};

int main() {

    int prices1[] = {3, 2, 6, 5, 0, 3};
    int k1 = 2;
    vector<int> pricesVec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(k1, pricesVec1) << endl;
    // 7

    int prices2[] = {2, 1, 4, 5, 2, 9, 7};
    int k2 = 2;
    vector<int> pricesVec2(prices2, prices2 + sizeof(prices2)/sizeof(int));
    cout << Solution().maxProfit(k2, pricesVec2) << endl;
    // 11

    return 0;
}