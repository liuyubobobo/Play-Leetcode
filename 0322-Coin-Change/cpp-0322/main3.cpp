/// Source : https://leetcode.com/problems/coin-change/solution/
/// Author : liuyubobobo
/// Time   : 2018-03-08

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Problem
/// 0-1 backpack problem
///
/// Time Complexity: O(coins_size * amount)
/// Space Complexity: O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i = 1 ; i <= amount ; i ++)
            for(int coin: coins)
                if(i - coin >= 0)
                    dp[i] = min(dp[i], dp[i-coin] + 1);

        return dp[amount] == amount + 1 ? -1 : dp[amount];
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