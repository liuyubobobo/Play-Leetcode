/// Source : https://leetcode.com/problems/longest-palindromic-substring/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// LCS
/// Attention: Just get LCS between s and reverse(s) doesn't work
/// Some small fixes is needed
/// See here for details: https://leetcode.com/problems/longest-palindromic-substring/solution/
///
/// Using only O(n) space
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    string longestPalindrome(string s) {

        if(s == "") return s;

        string rs = s;
        reverse(rs.begin(), rs.end());

        // lcs
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        string res = "";
        for(int i = 0; i < s.size(); i ++)
            for(int j = 0; j < rs.size(); j ++) {
                dp[(i + 1) % 2][j + 1] = (s[i] == rs[j]) ? dp[i % 2][j] + 1 : 0;
                if(dp[(i + 1) % 2][j + 1] > res.size() && i - dp[(i + 1) % 2][j + 1] + 1 == n - 1 - j)
                    res = s.substr(i - dp[(i + 1) % 2][j + 1] + 1, dp[(i + 1) % 2][j + 1]);
            }
        return res;
    }
};


int main() {

    cout << Solution().longestPalindrome("babad") << endl;

    return 0;
}