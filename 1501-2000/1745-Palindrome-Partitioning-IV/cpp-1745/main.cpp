/// Source : https://leetcode.com/problems/palindrome-partitioning-iv/
/// Author : liuyubobobo
/// Time   : 2021-01-30

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(|s|^2)
/// Space Complexity: O(|s|^2)
class Solution {
public:
    bool checkPartitioning(string s) {

        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>());

        dp[1] = vector<bool>(n, true);
        for(int i = 0; i + 1 < n; i ++)
            dp[2].push_back(s[i] == s[i + 1]);

        for(int sz = 3; sz <= n; sz ++)
            for(int i = 0; i + sz <= n; i ++)
                dp[sz].push_back((s[i] == s[i + sz - 1]) && dp[sz - 2][i + 1]);

        // [0 .. i - 1] [i .. j - 1] [j ... n - 1]
        for(int i = 1; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(dp[i][0] && dp[j - i][i] && dp[n - j][j])
                    return true;
        return false;
    }
};


int main() {

    cout << Solution().checkPartitioning("abcbdd") << endl;
    // 1

    cout << Solution().checkPartitioning("bcbddxy") << endl;
    // 0

    return 0;
}
