/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
/// Author : liuyubobobo
/// Time   : 2017-10-23

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() <= 1)
            return 0;

        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);

        buy[0] = -prices[0];
        buy[1] = max(-prices[0], -prices[1]);
        sell[1] = max(0, buy[0] + prices[1]);
        for(int i = 2 ; i < prices.size() ; i ++){
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
        }

        return sell.back();
    }
};


int main() {

    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices1) << endl;
    // 3

    return 0;
}