/// Source : https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>

using namespace std;


/// State Compression + Memory Search
/// Time Complexity: O(n * 40 * (1 << n))
/// Space Complexity: O(n + 40 * (1 << n))
class Solution {

private:
    const int MOD = 1e9 + 7;
    int n;

public:
    int numberWays(vector<vector<int>>& hats) {

        n = hats.size();
        for(vector<int>& v: hats) for(int& e: v) e --;

        vector<vector<int>> g(40, vector<int>());
        for(int i = 0; i < hats.size(); i ++)
            for(int hat: hats[i]) g[hat].push_back(i);

        vector<vector<int>> dp(40, vector<int>(1 << n, -1));
        return dfs(g, 0, 0, dp);
    }

private:
    int dfs(const vector<vector<int>>& g, int index, int state,
            vector<vector<int>>& dp){

        if(state == (1 << n) - 1) return 1;
        if(index == 40) return 0;
        if(dp[index][state] != -1) return dp[index][state];

        int res = dfs(g, index + 1, state, dp);
        for(int e: g[index])
            if((state & (1 << e)) == 0)
                res = (res + dfs(g, index + 1, state | (1 << e), dp)) % MOD;
        return dp[index][state] = res;
    }
};


int main() {

    vector<vector<int>> hats1 = {{3,4},{4,5},{5}};
    cout << Solution().numberWays(hats1) << endl;
    // 1

    vector<vector<int>> hats2 = {{3,5, 1},{3,5}};
    cout << Solution().numberWays(hats2) << endl;
    // 4

    return 0;
}
