/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
/// Author : liuyubobobo
/// Time   : 2019-06-27

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int n;

public:
    int maxProfit(vector<int>& prices) {

        n = prices.size();
        if(n <= 1) return 0;

        vector<int> buy(n, -1), sell(n, -1);
        return _sell(prices, n - 1, buy, sell);
    }

private:
    int _sell(const vector<int>& prices, int index, vector<int>& buy, vector<int>& sell){

        if(index == 0) return 0;
        if(index == 1) return max(0, prices[1] - prices[0]);

        if(sell[index] != -1) return sell[index];
        return sell[index] = max(_sell(prices, index - 1, buy, sell),
                                 _buy(prices, index - 1, buy, sell) + prices[index]);
    }

    int _buy(const vector<int>& prices, int index, vector<int>& buy, vector<int>& sell){

        if(index == 0) return -prices[0];
        if(index == 1) return max(-prices[0], -prices[1]);

        if(buy[index] != -1) return buy[index];
        return buy[index] = max(_buy(prices, index - 1, buy, sell),
                                _sell(prices, index - 2, buy, sell) - prices[index]);
    }
};


int main() {

    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices1) << endl;
    // 3

    return 0;
}