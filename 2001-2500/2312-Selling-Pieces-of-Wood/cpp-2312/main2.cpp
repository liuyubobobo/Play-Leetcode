/// Source : https://leetcode.com/problems/selling-pieces-of-wood/
/// Author : liuyubobobo
/// Time   : 2022-06-21

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DP
/// Time Complexity: O(m * n * (m + n))
/// Space Complexity: O(m * n)
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        vector<vector<bool>> visited(m + 1, vector<bool>(n + 1, false));

        for(const vector<int>& price: prices){
            int h = price[0], w = price[1], p = price[2];
            dp[h][w] = max(dp[h][w], 1ll * p);
        }

        return dfs(m, n, dp, visited);
    }

private:
    long long dfs(int m, int n, vector<vector<long long>>& dp, vector<vector<bool>>& visited){

        if(visited[m][n]) return dp[m][n];

        long long res = dp[m][n];
        for(int top = 1; top <= m - 1; top ++)
            res = max(res, dfs(top, n, dp, visited) + dfs(m - top, n, dp, visited));
        for(int left = 1; left <= n - 1; left ++)
            res = max(res, dfs(m, left, dp, visited) + dfs(m, n - left, dp, visited));

        visited[m][n] = true;
        return dp[m][n] = res;
    }
};


int main() {

    vector<vector<int>> prices1 = {{1, 4, 2}, {2, 2, 7}, {2, 1, 3}};
    cout << Solution().sellingWood(3, 5, prices1) << '\n';
    // 19

    vector<vector<int>> prices2 = {{3, 2, 10}, {1, 4, 2}, {4, 1, 3}};
    cout << Solution().sellingWood(4, 6, prices2) << '\n';
    // 32

    vector<vector<int>> prices3 = {{4, 1, 18}, {4, 2, 5}, {1, 1, 20}, {3, 1, 21}};
    cout << Solution().sellingWood(4, 2, prices3) << '\n';
    // 160

    return 0;
}
