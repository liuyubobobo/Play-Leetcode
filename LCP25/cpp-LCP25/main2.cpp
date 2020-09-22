/// Source : https://leetcode-cn.com/problems/Uh984O/
/// Author : liuyubobobo
/// Time   : 2020-09-21

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// State: dp[27][n]
/// Time Complexity: O(27kn)
/// Space Complexity: O(27n)
class Solution {

private:
    long long MOD = 1e9 + 7;
    vector<vector<int>> comb;

public:
    int keyboard(int k, int n) {

        comb = vector<vector<int>>(200, vector<int>(200, -1));

        vector<vector<int>> dp(27, vector<int>(n + 1, -1));
        return dfs(26, n, k, dp);
    }

    long long dfs(int index, int n, int k, vector<vector<int>>& dp){

        if(index == 0) return n == 0 ? 1 : 0;
        if(n == 0) return 1;
        if(dp[index][n] != -1) return dp[index][n];

        long long res = 0ll;
        for(int p = 0; p <= k && p <= n; p ++)
            res += dfs(index - 1, n - p, k, dp) * C(n, p), res %= MOD;
        return dp[index][n] = res;
    }

    long long C(int n, int k){

        if(n == k || k == 0) return 1ll;
        if(comb[n][k] != -1) return comb[n][k];

        return comb[n][k] = (C(n - 1, k) + C(n - 1, k - 1)) % MOD;
    }
};


int main() {

    cout << Solution().keyboard(1, 1) << endl;
    // 26

    cout << Solution().keyboard(1, 2) << endl;
    // 650

    cout << Solution().keyboard(1, 26) << endl;
    // 459042011

    cout << Solution().keyboard(2, 1) << endl;
    // 26

    cout << Solution().keyboard(2, 2) << endl;
    // 676

    cout << Solution().keyboard(5, 50) << endl;
    // 363766962

    return 0;
}
