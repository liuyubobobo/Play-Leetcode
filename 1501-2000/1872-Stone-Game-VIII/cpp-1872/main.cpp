/// Source : https://leetcode.com/problems/stone-game-viii/
/// Author : liuyubobobo
/// Time   : 2021-05-23

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();
        vector<int> sum(n, stones[0]);
        for(int i = 1; i < n; i ++)
            sum[i] = sum[i - 1] + stones[i];

        vector<int> dp(n, INT_MIN);
        return dfs(n, sum, 0, dp);
    }

private:
    int dfs(int n, const vector<int>& sum, int start, vector<int>& dp){

        if(start >= n - 1) return 0;
        if(start == n - 2) return sum[start + 1];
        if(dp[start] != INT_MIN) return dp[start];

        int res = max(sum[start + 1] - dfs(n, sum, start + 1, dp), dfs(n, sum, start + 1, dp));
        return dp[start] = res;
    }
};


int main() {

    vector<int> stones1 = {-1, 2, -3, 4, -5};
    cout << Solution().stoneGameVIII(stones1) << endl;
    // 5

    vector<int> stones2 = {7, -6, 5, 10, 5, -2, -6};
    cout << Solution().stoneGameVIII(stones2) << endl;
    // 13

    vector<int> stones3 = {-10, -12};
    cout << Solution().stoneGameVIII(stones3) << endl;
    // -22

    return 0;
}
