/// Source : https://leetcode.com/problems/longest-palindromic-subsequence-ii/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^2)
/// Space Coomplexity: O(n^2)
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(27, -1)));

        int res = 0;
        for(int i = 0; i < n; i ++)
            res = max(res, dfs(s, i, n - 1, 0, dp));
        return res;
    }

private:
    int dfs(const string& s, int l, int r, int p,
            vector<vector<vector<int>>>& dp){

        if(l >= r) return 0;
        if(dp[l][r][p] != -1) return dp[l][r][p];

        int res = dfs(s, l + 1, r, p, dp);
        if(s[l] - 'a' + 1 != p)
            for(int i = r; i > l; i --)
                if(s[i] == s[l]) res = max(res, 2 + dfs(s, l + 1, i - 1, s[l] - 'a' + 1, dp));
        return dp[l][r][p] = res;
    }
};


int main() {

    cout << Solution().longestPalindromeSubseq("bbabab") << endl;
    // 4

    cout << Solution().longestPalindromeSubseq("dcbccacdb") << endl;
    // 4

    return 0;
}
