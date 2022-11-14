/// Source : https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/
/// Author : liuyubobobo
/// Time   : 2022-11-12

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// DP
/// Time Complexity: O(n^2 + nk)
/// Space Complexity: O(n^2)
class Solution {
public:
    int maxPalindromes(string s, int k) {

        int n = s.size();

        vector<vector<bool>> is_palindrome(n, vector<bool>(n + 1, false)); // start, len
        for(int i = 0; i < n; i ++) is_palindrome[i][1] = is_palindrome[i][0] = true;
        for(int len = 2; len <= n; len ++)
            for(int i = 0; i + len <= n; i ++)
                if(s[i] == s[i + len - 1] && is_palindrome[i + 1][len - 2]) is_palindrome[i][len] = true;

        vector<int> dp(n + 1, INT_MIN / 2);
        dp[n] = 0;
        dp[n - 1] = (k == 1);
        for(int i = n - 2; i >= 0; i --){
            dp[i] = dp[i + 1];
            for(int len = k; i + len <= n; len ++)
                if(is_palindrome[i][len]) dp[i] = max(dp[i], 1 + dp[i + len]);
        }
        return dp[0] >= 0 ? dp[0] : 0;
    }
};


int main() {

    cout << Solution().maxPalindromes("abaccdbbd", 3) << '\n';
    // 2

    cout << Solution().maxPalindromes("adbcda", 2) << '\n';
    // 0

    cout << Solution().maxPalindromes("fttfjofpnpfydwdwdnns", 2) << '\n';
    // 4

    return 0;
}
