/// Source : https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// dp[0][i]: ending with a, dp[1][i]: ending with b
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();

        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        dp[0][0] = s[0] == 'b', dp[1][0] = s[0] == 'a';
        for(int i = 1; i < n; i ++){
            if(s[i] == 'a')
                dp[0][i] = dp[0][i - 1], dp[1][i] = dp[1][i - 1] + 1;
            else
                dp[0][i] = dp[0][i - 1] + 1, dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]);
        }
        return min(dp[0][n - 1], dp[1][n - 1]);
    }
};


int main() {

    cout << Solution().minimumDeletions("aababbab") << endl;
    // 2

    cout << Solution().minimumDeletions("a") << endl;
    // 0

    cout << Solution().minimumDeletions("aabbbbaabababbbbaaaaaabbababaaabaabaabbbabbbbabbabbababaabaababbbbaaaaabbabbabaaaabbbabaaaabbaaabbbaabbaaaaabaa") << endl;
    // 52

    return 0;
}
