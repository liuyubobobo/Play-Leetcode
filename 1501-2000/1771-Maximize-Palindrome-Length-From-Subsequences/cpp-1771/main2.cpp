/// Source : https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
/// Author : liuyubobobo
/// Time   : 2021-02-24

#include <iostream>
#include <vector>

using namespace std;


/// String Concatenating and DP
/// Time Complexity: O((n + m)^2)
/// Space Complexity: O((n + m)^2)
class Solution {

public:
    int longestPalindrome(string word1, string word2) {

        string s = word1 + word2;
        int len = s.size();

        vector<vector<int>> dp(len, vector<int>(len, -1));
        for(int i = 0; i < len; i ++) dp[i][i] = 1;

        int res = 0;
        for(int i = 0; i + 1 < len; i ++){
            dp[i][i + 1] = (s[i] == s[i + 1] ? 2 : 1);
            if(s[i] == s[i + 1] && i < word1.size() && i + 1 >= word1.size())
                res = 2;
        }

        for(int l = 3; l <= len; l ++)
            for(int i = 0; i + l <= len; i ++){
                dp[i][i + l - 1] = max(dp[i + 1][i + l - 1], dp[i][i + l - 2]);
                if(s[i] == s[i + l - 1])
                    dp[i][i + l - 1] = max(dp[i][i + l - 1], 2 + dp[i + 1][i + l - 2]);

                if(s[i] == s[i + l - 1] && i < word1.size() && i + l - 1 >= word1.size())
                    res = max(res, dp[i][i + l - 1]);
            }

        return res;
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

    cout << Solution().longestPalindrome("aba", "cfc") << endl;
    // 0

    return 0;
}
