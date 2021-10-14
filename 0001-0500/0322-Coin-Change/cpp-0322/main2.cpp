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

        vector<int> dp(amount+1, amount + 1);
        dp[0] = 0;

        for(int coin: coins)
            for(int j = coin ; j <= amount ; j ++)
                dp[j] = min(dp[j], dp[j-coin] + 1);

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};


int main() {

    vector<int> coins1 = {1, 2, 5};
    cout<< Solution().coinChange(coins1, 11) << endl;
    // 3

    vector<int> coins2 = {2};
    cout << Solution().coinChange(coins2, 1) << endl;
    // -1

    vector<int> coins3 = {2};
    int amount3 = 3;
    cout << Solution().coinChange(coins3, 3) << endl;
    // -1

    vector<int> coins4 = {2, 5, 10, 1};
    cout << Solution().coinChange(coins4, 27) << endl;
    // 4

    vector<int> coins5 = {186, 419, 83, 408};
    cout << Solution().coinChange(coins5, 6249) << endl;
    // 20

    return 0;
}