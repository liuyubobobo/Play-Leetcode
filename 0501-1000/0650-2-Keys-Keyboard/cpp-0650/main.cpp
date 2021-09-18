/// Source : https://leetcode.com/problems/2-keys-keyboard/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minSteps(int n) {

        if(n == 1) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return 1 + dfs(1, 1, n, dp);
    }

private:
    int dfs(int cur, int copy, int n, vector<vector<int>>& dp){

        if(cur == n) return 0;
        if(cur > n) return INT_MAX / 2;
        if(dp[cur][copy] != -1) return dp[cur][copy];

        int res = INT_MAX / 2;
        if(cur + copy <= n)
            res = min(res, 1 + dfs(cur + copy, copy, n, dp));
        if(cur + cur <= n)
            res = min(res, 2 + dfs(cur + cur, cur, n, dp));
        return dp[cur][copy] = res;
    }
};


int main() {

    cout << Solution().minSteps(3) << endl;
    // 3

    cout << Solution().minSteps(1) << endl;
    // 1

    return 0;
}
