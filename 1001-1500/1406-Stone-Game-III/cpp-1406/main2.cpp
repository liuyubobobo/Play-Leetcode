/// Source : https://leetcode.com/problems/stone-game-iii/
/// Author : liuyubobobo
/// Time   : 2020-04-08

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> postsum(n + 1, 0);
        for(int i = n - 1; i >= 0; i --) postsum[i] = postsum[i + 1] + stoneValue[i];

        vector<vector<int>> dp(2, vector<int>(n + 1, INT_MIN));
        dp[0][n] = dp[1][n] = 0;
        dp[0][n - 1] = dp[1][n - 1] = stoneValue[n - 1];

        for(int start = n - 2; start >= 0; start --)
            for(int player = 0; player <= 1; player ++){
                int sum = 0;
                for(int i = 0; i < 3 && start + i < n; i ++){
                    sum += stoneValue[start + i];
                    dp[player][start] = max(dp[player][start],
                                            sum + postsum[start + i + 1] - dp[1 - player][start + i + 1]);
                }
            }

        if(dp[0][0] > postsum[0] - dp[0][0]) return "Alice";
        else if(dp[0][0] < postsum[0] - dp[0][0]) return "Bob";
        return "Tie";
    }
};


int main() {

    vector<int> values1 = {1, 2, 3, 7};
    cout << Solution().stoneGameIII(values1) << endl;
    // Bob

    vector<int> values2 = {1, 2, 3, -9};
    cout << Solution().stoneGameIII(values2) << endl;
    // Alice

    vector<int> values3 = {1, 2, 3, 6};
    cout << Solution().stoneGameIII(values3) << endl;
    // Tie

    vector<int> values4 = {1,2,3,-1,-2,-3,7};
    cout << Solution().stoneGameIII(values4) << endl;
    // Alice

    vector<int> values5 = {-1, -2, -3};
    cout << Solution().stoneGameIII(values5) << endl;
    // Tie

    return 0;
}
