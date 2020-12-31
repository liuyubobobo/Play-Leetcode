/// Source : https://leetcode.com/problems/delete-operation-for-two-strings/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>

using namespace std;

/// LCS - Memory Search
/// Time Complexity: O(len(word1)*len(word2))
/// Space Complexity: O(len(word1)*len(word2))
class Solution {

private:
    vector<vector<int>> dp;

public:
    int minDistance(string word1, string word2) {

        dp.clear();
        for(int i = 0 ; i < word1.size() ; i ++)
            dp.push_back(vector<int>(word2.size(), -1));
        // cout << "LCS : " << lcs(word1, 0, word2, 0) << endl;
        return word1.size() + word2.size() - 2 * lcs(word1, 0, word2, 0);
    }

private:
    int lcs(const string& word1, int i1, const string& word2, int i2){

        if(i1 == word1.size() || i2 == word2.size())
            return 0;

        if(dp[i1][i2] != -1)
            return dp[i1][i2];

        int res = max(lcs(word1, i1 + 1, word2, i2),
                      lcs(word1, i1, word2, i2 + 1));
        if(word1[i1] == word2[i2])
            res = max(res, 1 + lcs(word1, i1 + 1, word2, i2 + 1));

        return dp[i1][i2] = res;
    }
};

int main() {

    cout << Solution().minDistance("sea", "eat") << endl;

    return 0;
}