/// Source : https://leetcode.com/problems/stone-game/description/
/// Author : liuyubobobo
/// Time   : 2018-08-02

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, -1)));

        for(int i = 0 ; i < n ; i ++){
            dp[0][i][i] = piles[i];
            dp[1][i][i] = -piles[i];
        }

        for(int sz = 2 ; sz <= n ; sz ++)
            for(int i = 0; i + sz - 1 < n ; i ++){
                dp[0][i][i + sz - 1] = max(piles[i] + dp[1][i + 1][i + sz - 1],
                                           piles[i + sz - 1] + dp[1][i][i + sz - 2]);
                dp[1][i][i + sz - 1] = max(-piles[i] + dp[0][i + 1][i + sz - 1],
                                           -piles[i + sz - 1] + dp[0][i][i + sz - 2]);
            }

        return dp[0][0][n - 1];
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