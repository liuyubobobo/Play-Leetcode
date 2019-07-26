/// Source : https://leetcode.com/problems/longest-palindromic-substring/
/// Author : liuyubobobo
/// Time   : 2019-01-11

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Dynamic Programming
/// State: is s.substr(start, len) a palindrome?
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {

        if(s == "") return s;

        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n + 1, true)); // start, len
        for(int len = 2; len <= n; len ++)
            for(int start = 0; start + len - 1 < n; start ++)
                dp[start][len] = (s[start] == s[start + len - 1] && dp[start + 1][len - 2]);
        for(int len = n; len >= 1; len --)
            for(int start = 0; start + len - 1 < n; start ++)
                if(dp[start][len])
                    return s.substr(start, len);
        return "";
    }
};


int main() {

    return 0;
}