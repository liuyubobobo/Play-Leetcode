/// Source : https://leetcode.com/problems/domino-and-tromino-tiling/description/
/// Author : liuyubobobo
/// Time   : 2018-03-08

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
///
/// Time Complexity: O(len(coins)*amount)
/// Space Complexity: O(len(coins)*amount)
class Solution {

private:
    vector<vector<int>> dp;

public:
    int change(int amount, vector<int>& coins) {

        dp = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        int res = search(coins, 0, amount);
        return res == -1 ? 0 : res;
    }

private:
    int search(const vector<int>& coins, int index, int amount){

        if(index == coins.size())
            return amount == 0 ? 1 : 0;

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int res = 0;
        for(int i = 0 ; i * coins[index] <= amount ; i ++)
            res += search(coins, index + 1, amount - i * coins[index]);
        return dp[index][amount] = res;
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