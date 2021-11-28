/// Source : https://leetcode.com/problems/guess-number-higher-or-lower-ii/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(1, n, dp);
    }

private:
    int dfs(int l, int r, vector<vector<int>>& dp){

        if(l == r) return 0;
        if(l + 1 == r) return l;
        if(l + 2 == r) return l + 1;
        if(dp[l][r] != -1) return dp[l][r];

        int res = INT_MAX;
        for(int root = l + 1; root < r; root ++){
            res = min(res, root + max(dfs(l, root - 1, dp), dfs(root + 1, r, dp)));
        }
        return dp[l][r] = res;
    }
};


int main() {

    cout << Solution().getMoneyAmount(10) << endl;
    // 16

    return 0;
}
