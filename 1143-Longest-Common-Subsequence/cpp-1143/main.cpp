/// Source : https://leetcode.com/problems/longest-common-subsequence/
/// Author : liuyubobobo
/// Time   : 2019-08-22

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n * m)
/// Space Complexity: O(n * m)
class Solution {

private:
    int n, m;

public:
    int longestCommonSubsequence(string s1, string s2) {

        n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dfs(s1, 0, s2, 0, dp);
    }

private:
    int dfs(const string& s1, int i, const string& s2, int j,
            vector<vector<int>>& dp){

        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = max(dfs(s1, i + 1, s2, j, dp), dfs(s1, i, s2, j + 1, dp));
        if(s1[i] == s2[j]) res = max(res, 1 + dfs(s1, i + 1, s2, j + 1, dp));
        return dp[i][j] = res;
    }
};


int main() {

    return 0;
}