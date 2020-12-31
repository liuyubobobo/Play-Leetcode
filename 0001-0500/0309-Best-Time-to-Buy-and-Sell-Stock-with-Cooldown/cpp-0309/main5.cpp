/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
/// Author : liuyubobobo
/// Time   : 2020-05-25

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Using three states every day, with space optimization
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if(n <= 1)
            return 0;

        int hold = -prices[0], sell = 0, unhold = 0;

        for(int i = 1 ; i < n ; i ++){
            hold = max(hold, unhold - prices[i]);
            unhold = max(sell, unhold);
            sell = hold + prices[i];
        }

        return max(unhold, sell);
    }
};


int main() {

    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices1) << endl;
    // 3

    return 0;
}