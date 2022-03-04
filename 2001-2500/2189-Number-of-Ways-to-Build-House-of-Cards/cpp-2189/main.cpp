/// Source : https://leetcode.com/problems/number-of-ways-to-build-house-of-cards/
/// Author : liuyubobobo
/// Time   : 2022-03-04

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int houseOfCards(int n) {

        if(n < 2) return 0;

        int max_count = 1 + (n - 2) / 3 + !!((n - 2) % 3);
        vector<vector<int>> dp(max_count + 1, vector<int>(n + 1, -1));
        return dfs(max_count, n, dp);
    }

private:
    int dfs(int max_count, int n, vector<vector<int>>& dp){

        if(n == 0) return 1;
        if(n == 1 || max_count == 0) return 0;
        if(dp[max_count][n] != -1) return dp[max_count][n];

        int res = dfs(0, n - 2, dp);
        for(int cnt = 5; cnt <= n && 1 + (cnt - 2) / 3 <= max_count; cnt += 3)
            res += dfs((cnt - 2) / 3, n - cnt, dp);
        return dp[max_count][n] = res;
    }
};


int main() {

    cout << Solution().houseOfCards(16) << '\n';
    // 2

    cout << Solution().houseOfCards(2) << '\n';
    // 1

    cout << Solution().houseOfCards(4) << '\n';
    // 0

    return 0;
}
