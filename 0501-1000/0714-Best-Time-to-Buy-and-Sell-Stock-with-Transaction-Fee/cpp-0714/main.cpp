/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
/// Author : liuyubobobo
/// Time   : 2017-10-24

#include <iostream>
#include <vector>

using namespace std;

/// Using hold and cash to trace the max money in different state
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        if(prices.size() <= 1)
            return 0;

        int hold[2] = {-prices[0], 0};
        int cash[2] = {0, 0};
        for(int i = 1 ; i < prices.size() ; i ++){
            hold[i%2] = max(hold[(i-1)%2], cash[(i-1)%2] - prices[i]);
            cash[i%2] = max(cash[(i-1)%2], hold[(i-1)%2] + prices[i] - fee);
        }

        return cash[(prices.size()-1)%2];
    }
};

int main() {

    int prices1[] = {1, 3, 2, 8, 4, 9};
    int fee1 = 2;
    vector<int> vec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(vec1, fee1) << endl;

    return 0;
}