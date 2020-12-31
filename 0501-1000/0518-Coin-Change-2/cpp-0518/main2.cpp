/// Source : https://leetcode.com/problems/domino-and-tromino-tiling/description/
/// Author : liuyubobobo
/// Time   : 2018-03-08

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
///
/// Time Complexity: O(len(coins)*amount*log(amount))
/// Space Complexity: O(len(coins)*amount)
class Solution {

public:
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[coins.size()][0] = 1;
        for(int i = coins.size() - 1; i >= 0 ; i --)
            for(int j = 0; j <= amount; j ++)
                for(int k = 0 ; k * coins[i] <= j ; k ++)
                    dp[i][j] += dp[i + 1][j - k * coins[i]];
        return dp[0][amount];
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