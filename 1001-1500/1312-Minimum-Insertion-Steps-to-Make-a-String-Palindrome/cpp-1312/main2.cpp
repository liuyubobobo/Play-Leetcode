/// Source : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
/// Author : liuyubobobo
/// Time   : 2020-01-14

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minInsertions(string s) {

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), INT_MAX));
        for(int i = 0; i < s.size(); i ++) dp[i][i] = 0;
        for(int i = 0; i + 1 < s.size(); i ++) dp[i][i + 1] = s[i] == s[i + 1] ? 0 : 1;
        for(int len = 3; len <= s.size(); len ++)
            for(int i = 0; i + len - 1 < s.size(); i ++)
                dp[i][len + i - 1] = s[i] == s[len + i - 1] ? dp[i + 1][len + i - 2] :
                                     1 + min(dp[i + 1][len + i - 1], dp[i][len + i - 2]);
        return dp[0][s.size() - 1];
    }
};


int main() {

    cout << Solution().minInsertions("zzazz") << endl;
    // 0

    cout << Solution().minInsertions("mbadm") << endl;
    // 2

    cout << Solution().minInsertions("leetcode") << endl;
    // 5

    cout << Solution().minInsertions("zjveiiwvc") << endl;
    // 5

    return 0;
}
