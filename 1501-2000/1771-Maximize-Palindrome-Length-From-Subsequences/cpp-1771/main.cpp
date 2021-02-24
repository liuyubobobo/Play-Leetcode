/// Source : https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
/// Author : liuyubobobo
/// Time   : 2021-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// And pre-calculate max palindrome string length from each string seperately
/// Time Complexity: O(n^2 + m^2 + m * n)
/// Space Complexity: O(n^2 + m^2 + m * n)
class Solution {

private:
    int n, m;

public:
    int longestPalindrome(string word1, string word2) {

        n = word1.size(), m = word2.size();

        vector<vector<int>> dp1(n, vector<int>(n, -1));
        go(word1, n, dp1);

        vector<vector<int>> dp2(m, vector<int>(m, -1));
        go(word2, m, dp2);

        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(m, -1)));
        return dfs(word1, word2, 0, 0, m - 1, dp, dp1, dp2);
    }

private:
    void go(const string& s, int len, vector<vector<int>>& dp){

        for(int i = 0; i < len; i ++) dp[i][i] = 1;
        for(int i = 0; i + 1 < len; i ++)
            dp[i][i + 1] = (s[i] == s[i + 1] ? 2 : 1);

        for(int l = 3; l <= len; l ++)
            for(int i = 0; i + l <= len; i ++){
                dp[i][i + l - 1] = max(dp[i + 1][i + l - 1], dp[i][i + l - 2]);
                if(s[i] == s[i + l - 1])
                    dp[i][i + l - 1] = max(dp[i][i + l - 1], 2 + dp[i + 1][i + l - 2]);
            }
    }

    int dfs(const string& s1, const string& s2, int ok, int l, int r,
            vector<vector<vector<int>>>& dp,
            vector<vector<int>>& dp1, vector<vector<int>>& dp2){

        if(l >= s1.size() && r < 0) return 0;

        if(l >= s1.size()) return ok ? dp2[0][r] : 0;
        if(r < 0) return ok ? dp1[l][n - 1] : 0;

        if(dp[ok][l][r] != -1) return dp[ok][l][r];

        int res = dfs(s1, s2, ok, l + 1, r, dp, dp1, dp2);
        res = max(res, dfs(s1, s2, ok, l, r - 1, dp, dp1, dp2));
        if(s1[l] == s2[r])
            res = max(res, 2 + dfs(s1, s2, 1, l + 1, r - 1, dp, dp1, dp2));
//        cout << ok << " " << l << " " << r << " : " << res << endl;
        return dp[ok][l][r] = res;
    }
};


int main() {

    cout << Solution().longestPalindrome("cacb", "cbba") << endl;
    // 5

    cout << Solution().longestPalindrome("ab", "ab") << endl;
    // 3

    cout << Solution().longestPalindrome("aa", "bb") << endl;
    // 0

    cout << Solution().longestPalindrome("aaa", "a") << endl;
    // 4

    cout << Solution().longestPalindrome("aaaada", "ca") << endl;
    // 6

    return 0;
}
