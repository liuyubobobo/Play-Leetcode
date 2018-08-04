/// Source : https://leetcode.com/problems/stone-game/description/
/// Author : liuyubobobo
/// Time   : 2018-07-28

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n, INT_MIN)));

        return play(0, piles, 0, n-1, dp) > 0;
    }

private:
    int play(int player, const vector<int>& piles, int l, int r,
                vector<vector<vector<int>>>& dp){

        if(l == r){
            if(player == 0)
                return dp[player][l][r] = piles[l];
            else
                return dp[player][l][r] = -piles[l];
        }

        if(dp[player][l][r] != INT_MIN)
            return dp[player][l][r];

        int res = 0;
        if(player == 0)
            res = max(piles[l] + play(1 - player, piles, l + 1, r, dp),
                      piles[r] + play(1 - player, piles, l, r - 1, dp));
        else
            res = max(-piles[l] + play(1 - player, piles, l + 1, r, dp),
                      -piles[r] + play(1 - player, piles, l, r - 1, dp));
        return dp[player][l][r] = res;
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