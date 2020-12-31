/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
/// Author : liuyubobobo
/// Time   : 2017-10-22

#include <iostream>
#include <vector>

using namespace std;

/// Using first and second to trace all the possible transactions
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 0)
            return 0;

        // first[i] is the max profit within day[0...i]
        vector<int> first(prices.size(), 0);
        int minPrice = prices[0];
        for(int i = 1 ; i < prices.size() ; i ++){
            first[i] = max(first[i-1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

//        cout << "first" << endl;
//        for(int i = 0 ; i < first.size() ; i ++)
//            cout << first[i] << ((i == first.size() - 1) ? "\n" : " ");

        // second[i] is the max profit within day[i...n)
        vector<int> second(prices.size(), 0);
        int maxPrice = prices.back();
        for(int i = prices.size() - 2 ; i >= 0 ; i --){
            second[i] = max(second[i+1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }

//        cout << "second" << endl;
//        for(int i = 0 ; i < second.size() ; i ++)
//            cout << second[i] << ((i == second.size() - 1) ? "\n" : " ");

        int res = second[0];
        for(int i = 0 ; i < prices.size()-1 ; i ++)
            res = max(res, first[i] + second[i+1]);
        res = max(res, first.back());

        return res;
    }
};

int main() {

    int prices1[] = {1, 2};
    vector<int> pricesVec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(pricesVec1) << endl;

    return 0;
}