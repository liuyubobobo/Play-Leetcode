/// Source : https://leetcode.com/problems/longest-palindromic-substring/
/// Author : liuyubobobo
/// Time   : 2019-01-11

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Memory Search
/// State: is s[a...b] a palindrome?
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {

        if(s == "") return s;

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // s[a...b]
        for(int len = n; len >= 1; len --)
            for(int start = 0; start + len - 1 < n; start ++)
                if(dfs(s, start, start + len - 1, dp))
                    return s.substr(start, len);
        return "";
    }

private:
    int dfs(const string& s, int a, int b,
             vector<vector<int>>& dp){

        if(a > b) return dp[a][b] = 0;
        if(a == b || (a + 1 == b && s[a] == s[b])) return dp[a][b] = 1;
        if(dp[a][b] != -1) return dp[a][b];

        if(s[a] != s[b]) return dp[a][b] = 0;
//        assert(s[a] == s[b]);
        return dp[a][b] = dfs(s, a + 1, b - 1, dp);
    }
};


int main() {

    return 0;
}