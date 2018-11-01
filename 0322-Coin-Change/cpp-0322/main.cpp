/// Source : https://leetcode.com/problems/coin-change/solution/
/// Author : liuyubobobo
/// Time   : 2018-03-08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Memory Search
///
/// Time Complexity: O(coins_size * amount)
/// Space Complexity: O(amount)
class Solution {

private:
    vector<int> dp;
    int max_amount;

public:
    int coinChange(vector<int>& coins, int amount) {
        max_amount = amount + 1;
        dp = vector<int>(amount+1, -1);
        int res = search(coins, amount);
        return res == max_amount ? -1 : res;
    }

private:
    int search(const vector<int>& coins, int amount){

        if(amount == 0)
            return 0;

        if(dp[amount] != -1)
            return dp[amount];

        int res = max_amount;
        for(int coin: coins)
            if(amount - coin >= 0)
                res = min(res, 1 + search(coins, amount -coin));
        return dp[amount] = res;
    }
};


int main() {

    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout<< Solution().coinChange(coins1, amount1) << endl;
    // 3

    // ---

    vector<int> coins2 = {2};
    int amount2 = 1;
    cout << Solution().coinChange(coins2, amount2) << endl;
    // -1

    // ---

    vector<int> coins3 = {2};
    int amount3 = 3;
    cout << Solution().coinChange(coins3, amount3) << endl;
    // -1

    // ---

    vector<int> coins4 = {2, 5, 10, 1};
    int amount4 = 27;
    cout << Solution().coinChange(coins4, amount4) << endl;
    // 4

    // ---

    vector<int> coins5 = {186, 419, 83, 408};
    int amount5 = 6249;
    cout << Solution().coinChange(coins5, amount5) << endl;
    // 20

    return 0;
}