/// Source : https://leetcode.com/problems/delete-operation-for-two-strings/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Directly solve the minimum deleted character number problem
///
/// Time Complexity: O(len(word1)*len(word2))
/// Space Complexity: O(len(word1)*len(word2))
class Solution {

public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 0 ; i <= word1.size() ; i ++)
            dp[i][0] = i;
        for(int j = 0 ; j <= word2.size() ; j ++)
            dp[0][j] = j;

        for(int i = 1 ; i <= word1.size() ; i ++)
            for(int j = 1 ; j <= word2.size() ; j ++){
                dp[i][j] = min(1 + dp[i-1][j], 1 + dp[i][j-1]);
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
        return dp[word1.size()][word2.size()];
    }
};

int main() {

    cout << Solution().minDistance("sea", "eat") << endl;

    return 0;
}