#include <iostream>
#include <vector>

using namespace std;

/// Memory Search
/// Time Complexity: O(n*n*k)
/// Space Complexity: O(n*k)
class Solution {

private:
    int **dp;  // dp[i][j], start from day[i],
               // the most profit to complete at most j transactions.

public:
    int maxProfit(int k, vector<int>& prices) {

        if(k >= prices.size()/2)
            return maxProfit(prices);

        dp = new int*[prices.size()];
        for(int i = 0 ; i < prices.size() ; i ++){
            dp[i] = new int[k+1];
            for(int j = 0 ; j <= k ; j ++)
                dp[i][j] = -1;
        }

        int res = solve(prices, 0, k);

        for(int i = 0 ; i < prices.size() ; i ++)
            delete[] dp[i];
        delete[] dp;

        return res;
    }

private:
    int solve(const vector<int>& prices, int startIndex, int left){

        if(startIndex >= prices.size() || left == 0)
            return 0;

        if(dp[startIndex][left] != -1)
            return dp[startIndex][left];

        int minPrice = prices[startIndex];
        int best = 0;
        for(int i = startIndex + 1 ; i < prices.size() ; i ++)
            if(prices[i] > minPrice)
                best = max(best, prices[i] - minPrice + solve(prices, i + 1, left - 1));
            else{
                best = max(best, solve(prices, i + 1, left-1));
                minPrice = prices[i];
            }

        return dp[startIndex][left] = best;
    }

    int maxProfit(const vector<int>& prices){
        int res = 0;
        for(int i = 1 ; i < prices.size() ; i ++)
            if(prices[i] > prices[i-1])
                res += (prices[i] - prices[i-1]);
        return res;
    }
};

int main() {

    int prices1[] = {1, 2};
    int k1 = 1;
    vector<int> pricesVec1(prices1, prices1 + sizeof(prices1)/sizeof(int));
    cout << Solution().maxProfit(k1, pricesVec1) << endl;

    return 0;
}