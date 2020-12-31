/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-10-22

#include <iostream>
#include <vector>

using namespace std;

/// Find every peak and vally in prices
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 0)
            return 0;

        vector<int> peakAndValley;
        peakAndValley.push_back(0);
        int i = 1;
        while(i < prices.size()){

            while(i < prices.size() && prices[i] >= prices[i-1])
                i ++;
            if(i-1 != peakAndValley.back())
                peakAndValley.push_back(i-1);

            while(i < prices.size() && prices[i] <= prices[i-1])
                i ++;
            if(i-1 != peakAndValley.back())
                peakAndValley.push_back(i-1);
        }

//        cout << "peakAndvalley size = "<< peakAndValley.size() << endl;
//        for(int i = 0 ; i < peakAndValley.size() ; i ++)
//            cout << peakAndValley[i] << ((i == peakAndValley.size() - 1) ? "\n" : " ");

        int res = 0;
        for(int i = 1 ; i < peakAndValley.size() ; i ++)
            if(prices[peakAndValley[i]] > prices[peakAndValley[i-1]])
                res += (prices[peakAndValley[i]] - prices[peakAndValley[i-1]]);

        return res;
    }
};

int main() {

    int prices1[] = {1, 2};
    vector<int> pricesVec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(pricesVec1) << endl;

    return 0;
}