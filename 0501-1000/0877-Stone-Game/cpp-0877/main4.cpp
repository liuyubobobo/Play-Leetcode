/// Source : https://leetcode.com/problems/stone-game/description/
/// Author : liuyubobobo
/// Time   : 2018-08-03

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Just use 2d dp array and consider two moves by each player together:)
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        for(int i = 0; i + 1 < n; i ++ )
            dp[i][i + 1] = abs(piles[i] - piles[i + 1]);

        for(int sz = 4; sz <= n; sz ++)
            for(int i = 0; i + sz - 1 < n; i ++)
                dp[i][i + sz - 1] = max(
                        abs(piles[i] - piles[i + 1]) + dp[i + 2][i + 3],
                        abs(piles[i] - piles[i + sz - 1]) + dp[i + 1][i + sz - 2]);
        return dp[0][n - 1];
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<int> piles1 = {5, 3, 4, 5};
    print_bool(Solution().stoneGame(piles1));

    return 0;
}