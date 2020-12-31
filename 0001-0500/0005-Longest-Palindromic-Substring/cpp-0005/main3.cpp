/// Source : https://leetcode.com/problems/longest-palindromic-substring/
/// Author : liuyubobobo
/// Time   : 2019-01-11

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Memory Search
/// State: is s.substr(start, len) a palindrome?
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {

        if(s == "") return s;

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // start, len
        for(int len = n; len >= 1; len --)
            for(int start = 0; start + len - 1 < n; start ++)
                if(dfs(s, start, len, dp))
                    return s.substr(start, len);
        return "";
    }

private:
    int dfs(const string& s, int start, int len, vector<vector<int>>& dp){

        if(len <= 1) return dp[start][len] = 1;
        if(dp[start][len] >= 0) return dp[start][len];
        return dp[start][len] =
                (s[start] == s[start + len - 1] && dfs(s, start + 1, len - 2, dp));
    }
};


int main() {

    return 0;
}