/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
/// Author : liuyubobobo
/// Time   : 2017-10-23

#include <iostream>
#include <vector>

using namespace std;

/// Using hold and cash to trace the max money in different state
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() <= 1)
            return 0;

        vector<int> hold(prices.size(), INT_MIN);
        vector<int> cash(prices.size(), 0);

        hold[0] = -prices[0];
        hold[1] = max(hold[0], -prices[1]);
        cash[1] = max(cash[0], hold[0] + prices[1]);
        for(int i = 2 ; i < prices.size() ; i ++){
            cash[i] = max(cash[i-1], hold[i-1] + prices[i]);
            hold[i] = max(hold[i-1], cash[i-2] - prices[i]);
        }

        return cash.back();
    }
};

int main() {

    int prices1[] = {1, 2, 3, 0, 2};
    vector<int> vec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(vec1) << endl;

    return 0;
}