/// Source : https://leetcode.com/problems/stone-game/description/
/// Author : liuyubobobo
/// Time   : 2022-08-14

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        return play(piles, 0, n-1, dp) > 0;
    }

private:
    int play(const vector<int>& piles, int l, int r,
             vector<vector<int>>& dp){

        if(l == r) return piles[l];

        if(dp[l][r] != INT_MIN)
            return dp[l][r];

        int res = max(piles[l] - play(piles, l + 1, r, dp),
                      piles[r] - play(piles, l, r - 1, dp));
        return dp[l][r] = res;
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