/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
/// Author : liuyubobobo
/// Time   : 2017-10-23

#include <iostream>
#include <vector>

using namespace std;

/// Using hold and cash
/// Time Complexity: O(n*k)
/// Space Complexity: O(2*k)
class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {

        if(k >= prices.size()/2)
            return maxProfit(prices);

        if(k <= 0)
            return 0;

        vector<int> hold(k+1, INT_MIN);
        vector<int> cash(k+1, 0);

        for(int price: prices)
            for(int j = k ; j >= 1 ; j --){
                cash[j] = max(cash[j], hold[j] + price);
                hold[j] = max(hold[j], cash[j-1] - price);
            }

        return cash.back();
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