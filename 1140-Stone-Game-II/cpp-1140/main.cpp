/// Source : https://leetcode.com/problems/stone-game-ii/
/// Author : liuyubobobo
/// Time   : 2019-07-27

#include <iostream>
#include <map>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
private:
    int n;
    vector<int> sum;

public:
    int stoneGameII(vector<int>& piles) {

        n = piles.size();
        sum.push_back(0);
        for(int e: piles) sum.push_back(sum.back() + e);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(1, 0, dp);
    }

    int dfs(int M, int end, vector<vector<int>>& dp){

        if(end == n) return 0;
        if(dp[M][end] != -1) return dp[M][end];

        int res = 0;
        for(int i = end; i < min(end + 2 * M, n); i ++)
            res = max(res, sum[n] - sum[end] - dfs(max(i - end + 1, M), i + 1, dp));
        return dp[M][end] = res;
    }
};


int main() {
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << Solution().stoneGameII(piles) << endl;
    // 10
    return 0;
}