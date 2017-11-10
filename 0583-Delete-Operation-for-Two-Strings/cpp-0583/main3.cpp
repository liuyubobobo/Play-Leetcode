/// Source : https://leetcode.com/problems/delete-operation-for-two-strings/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>

using namespace std;

/// LCS - Dynamic Programming with Rolling Array
/// Time Complexity: O(len(word1)*len(word2))
/// Space Complexity: O(len(word2))
class Solution {

public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(2, vector<int>(word2.size() + 1, 0));
        for(int i = 1 ; i <= word1.size() ; i ++)
            for(int j = 1 ; j <= word2.size() ; j ++){
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
                if(word1[i-1] == word2[j-1])
                    dp[i%2][j] = max(dp[i%2][j], 1 + dp[(i-1)%2][j-1]);
            }
        return word1.size() + word2.size() - 2 * dp[word1.size()%2][word2.size()];
    }
};

int main() {

    cout << Solution().minDistance("sea", "eat") << endl;

    return 0;
}