/// Source : https://leetcode.com/problems/domino-and-tromino-tiling/description/
/// Author : liuyubobobo
/// Time   : 2018-03-08

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
///
/// Time Complexity: O(len(coins)*amount)
/// Space Complexity: O(amount)
class Solution {

public:
    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = coins.size() - 1; i >= 0 ; i --)
            for(int j = coins[i]; j <= amount; j ++)
                dp[j] += dp[j - coins[i]];
        return dp[amount];
    }
};

int main() {

    vector<int> coins1 = {1, 2, 5};
    cout << Solution().change(5, coins1) << endl;

    vector<int> coins2 = {2};
    cout << Solution().change(3, coins2) << endl;

    vector<int> coins3 = {10};
    cout << Solution().change(10, coins3) << endl;

    return 0;
}