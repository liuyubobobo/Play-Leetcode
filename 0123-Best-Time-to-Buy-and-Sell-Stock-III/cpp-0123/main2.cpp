/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
/// Author : liuyubobobo
/// Time   : 2017-10-22

#include <iostream>
#include <vector>

using namespace std;

/// Using hold and cash to trace the max money in different state
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 0)
            return 0;

        int hold1 = INT_MIN;
        int cash1 = 0;
        int hold2 = INT_MIN;
        int cash2 = 0;
        for(int price : prices) {
            cash2 = max(cash2, hold2 + price);
            hold2 = max(hold2, cash1 - price);
            cash1 = max(cash1, hold1 + price);
            hold1 = max(hold1, -price);
        }

        return cash2;
    }
};

int main() {

    int prices1[] = {1, 2};
    vector<int> pricesVec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(pricesVec1) << endl;

    return 0;
}