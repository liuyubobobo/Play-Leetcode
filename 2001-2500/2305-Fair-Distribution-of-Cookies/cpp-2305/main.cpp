/// Source : https://leetcode.com/problems/fair-distribution-of-cookies/
/// Author : liuyubobobo
/// Time   : 2022-06-11

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(k * 3^n)
/// Space Complexity: O(k * 2^n)
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {

        int n = cookies.size();

        vector<int> table(1 << n, 0);
        for(int state = 1; state < (1 << n); state ++){
            int p = __builtin_ffs(state) - 1;
            table[state] = table[state - (1 << p)] + cookies[p];
        }

        vector<vector<int>> dp(k + 1, vector<int>(1 << n, -1));
        return dfs((1 << n) - 1, k, table, dp);
    }

private:
    int dfs(int state, int k, const vector<int>& table, vector<vector<int>>& dp){

        if(k == 1) return table[state];
        if(dp[k][state] != -1) return dp[k][state];

        int res = table[state];
        for (int s = state; s; s = (s - 1) & state) {
            res = min(res, max(table[s], dfs(state - s, k - 1, table, dp)));
        }
        return dp[k][state] = res;
    }
};


int main() {

    return 0;
}
