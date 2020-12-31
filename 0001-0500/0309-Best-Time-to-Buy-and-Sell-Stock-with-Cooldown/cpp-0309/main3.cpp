/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
/// Author : liuyubobobo
/// Time   : 2017-10-24

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming with Space Optimization
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if(n <= 1)
            return 0;

        int buy[3] = {-prices[0], max(-prices[0], -prices[1]), 0};
        int sell[3] = {0, max(0, prices[1] - prices[0]), 0};

        for(int i = 2 ; i < n ; i ++){
            sell[i % 3] = max(sell[(i - 1) % 3], buy[(i - 1) % 3] + prices[i]);
            buy[i % 3] = max(buy[(i - 1) % 3], sell[(i - 2) % 3] - prices[i]);
        }

        return sell[(n - 1) % 3];
    }
};


int main() {

    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices1) << endl;
    // 3

    return 0;
}