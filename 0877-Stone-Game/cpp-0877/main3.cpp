/// Source : https://leetcode.com/problems/stone-game/description/
/// Author : liuyubobobo
/// Time   : 2018-08-03

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Just use 2d dp array and consider two moves by each player together:)
///
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
    int play(const vector<int>& piles, int l, int r, vector<vector<int>>& dp){

        if(l + 1 == r)
            return abs(piles[l] - piles[r]);

        if(dp[l][r] != INT_MIN)
            return dp[l][r];

        return dp[l][r] = max(
                abs(piles[l] - piles[l + 1]) + play(piles, l + 2, r, dp),
                abs(piles[l] - piles[r]) + play(piles, l + 1, r - 1, dp));
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