/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
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
    int maxProfit(vector<int>& prices) {

        if(prices.size() <= 1)
            return 0;

        int hold[3] = {-prices[0], max(hold[0], -prices[1]), INT_MIN};
        int cash[3] = {0, max(cash[0], hold[0] + prices[1]), 0};

        for(int i = 2 ; i < prices.size() ; i ++){
            cash[i%3] = max(cash[(i-1)%3], hold[(i-1)%3] + prices[i]);
            hold[i%3] = max(hold[(i-1)%3], cash[(i-2)%3] - prices[i]);
        }

        return cash[(prices.size()-1)%3];
    }
};

int main() {

    int prices1[] = {1, 2, 3, 0, 2};
    vector<int> vec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(vec1) << endl;

    return 0;
}