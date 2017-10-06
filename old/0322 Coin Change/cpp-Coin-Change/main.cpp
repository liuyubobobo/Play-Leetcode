#include <iostream>
#include <vector>

using namespace std;

/// Problem
/**********************************************************************************************
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount.
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 *
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 *********************************************************************************************/


/// Solution
/**************************************************************************************
 * 0-1 backpack problem
 *
 * Time Complexity: O(coins_size*amount)
 * Space Complexity: O(amount)
 **************************************************************************************/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        sort( coins.begin() , coins.end() );

        vector<int> dp(amount+1, coins.size() * amount + 1);
        dp[0] = 0;

        for( int i = 0 ; i < coins.size() ; i ++ ){

            for( int j = coins[i] ; j <= amount ; j ++ )
                if( dp[j-coins[i]] != -1 )
                    dp[j] = min( dp[j], dp[j-coins[i]] + 1);

        }

        if( dp[amount] == coins.size() * amount + 1 )
            return -1;
        return dp[amount];
    }
};

int main() {

    int coins1[] = {1, 2, 5};
    vector<int> vec1( coins1, coins1 + sizeof(coins1)/sizeof(int));
    int amount1 = 11;
    cout<<Solution().coinChange( vec1, amount1 )<<endl;

    int coins2[] = {2};
    vector<int> vec2( coins2, coins2 + sizeof(coins2)/sizeof(int));
    int amount2 = 1;
    cout<<Solution().coinChange( vec2, amount2 )<<endl;

    int coins3[] = {2};
    vector<int> vec3( coins3, coins3 + sizeof(coins3)/sizeof(int));
    int amount3 = 3;
    cout<<Solution().coinChange( vec3, amount3 )<<endl;

    int coins4[] = {2, 5, 10, 1};
    vector<int> vec4( coins4, coins4 + sizeof(coins4)/sizeof(int));
    int amount4 = 27;
    cout<<Solution().coinChange( vec4, amount4 )<<endl;

    int coins5[] = {186, 419, 83, 408};
    vector<int> vec5( coins5, coins5 + sizeof(coins5)/sizeof(int));
    int amount5 = 6249;
    cout<<Solution().coinChange( vec5, amount5 )<<endl;

    return 0;
}