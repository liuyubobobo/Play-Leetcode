/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-10-22

#include <iostream>
#include <vector>

using namespace std;

/// Every rise price can be a part of profit
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int res = 0;
        for(int i = 1 ; i < prices.size() ; i ++)
            if(prices[i] > prices[i-1])
                res += (prices[i] - prices[i-1]);

        return res;
    }
};

int main() {

    int prices1[] = {1, 2};
    vector<int> pricesVec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(pricesVec1) << endl;

    return 0;
}