/// Source : https://leetcode.com/problems/longest-common-subsequence/
/// Author : liuyubobobo
/// Time   : 2019-08-22

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n * m)
/// Space Complexity: O(n * m)
class Solution {

public:
    int longestCommonSubsequence(string s1, string s2) {

        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++){
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                if(s1[i] == s2[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], 1 + dp[i][j]);
            }
        return dp[n][m];
    }
};


int main() {

    return 0;
}