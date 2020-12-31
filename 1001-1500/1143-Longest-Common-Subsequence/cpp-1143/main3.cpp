/// Source : https://leetcode.com/problems/longest-common-subsequence/
/// Author : liuyubobobo
/// Time   : 2019-08-22

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming with Space Optimization
/// Time Complexity: O(n * m)
/// Space Complexity: O(m)
class Solution {

public:
    int longestCommonSubsequence(string s1, string s2) {

        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++){
                dp[(i + 1) % 2][j + 1] = max(dp[i % 2][j + 1], dp[(i + 1) % 2][j]);
                if(s1[i] == s2[j]) dp[(i + 1) % 2][j + 1] = max(dp[(i + 1) % 2][j + 1], 1 + dp[i % 2][j]);
            }
        return dp[n % 2][m];
    }
};


int main() {

    return 0;
}