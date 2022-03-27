/// Source : https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
/// Author : liuyubobobo
/// Time   : 2022-03-26

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Memoization
/// Time Complexity: O(n * k)
/// Space Complexity: O(n * k)
class Solution {

public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MIN));
        return dfs(n, piles, 0, k, dp);
    }

private:
    int dfs(int n, const vector<vector<int>>& piles,
            int index, int k, vector<vector<int>>& dp){

        if(k == 0) return 0;
        if(index == n) return INT_MIN / 2;
        if(dp[index][k] != INT_MIN) return dp[index][k];

        int res = dfs(n, piles, index + 1, k, dp);
        int sum = 0, cnt = 0;
        for(int e: piles[index]){
            sum += e;
            cnt ++;
            if(cnt > k) break;
            res = max(res, sum + dfs(n, piles, index + 1, k - cnt, dp));
        }
        return dp[index][k] = res;
    }
};


int main() {

    vector<vector<int>> piles1 = {{1, 100, 3}, {7, 8, 9}};
    cout << Solution().maxValueOfCoins(piles1, 2) << '\n';
    // 101

    vector<vector<int>> piles2 = {{100}, {100}, {100}, {100}, {100}, {100}, {1,1,1,1,1,1,700}};
    cout << Solution().maxValueOfCoins(piles2, 7) << '\n';
    // 706

    return 0;
}
