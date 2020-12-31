/// Source : https://leetcode.com/problems/longest-palindromic-subsequence/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(s, 0, n - 1, dp);
    }

private:
    int dfs(const string& s, int l, int r, vector<vector<int>>& dp){

        if(l > r) return 0;
        if(l == r) return 1;
        if(dp[l][r] != -1) return dp[l][r];

        int res = dfs(s, l + 1, r, dp);
        for(int i = r; i > l; i --)
            if(s[i] == s[l]){
                res = max(res, 2 + dfs(s, l + 1, i - 1, dp));
                break;
            }
        return dp[l][r] = res;
    }
};


int main() {

    return 0;
}
