/// Source : https://leetcode.com/problems/edit-distance/
/// Author : liuyubobobo
/// Time   : 2018-11-23

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(len(word1) * len(word2))
/// Space Complexity: O(len(word1) * len(word2))
class Solution {

public:
    int minDistance(string word1, string word2) {

        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        for(int i = 0; i <= m; i ++)
            dp[i][0] = i;
        for(int j = 0; j <= n; j ++)
            dp[0][j] = j;

        // get dp[i][j], check word[i - 1], word[j - 1]
        for(int i = 1; i <= m; i ++)
            for(int j = 1; j <= n; j ++){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
            }

        return dp[m][n];
    }
};


int main() {

    return 0;
}