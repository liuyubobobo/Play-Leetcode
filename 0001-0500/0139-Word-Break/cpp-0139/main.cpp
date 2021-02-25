/// Source : https://leetcode.com/problems/word-break/
/// Author : liuyubobobo
/// Time   : 2021-02-25

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(|s| * |wordDict|)
/// Space Complexity: O(|s|)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> dp(s.size(), -1);
        return dfs(s, 0, wordDict, dp);
    }

private:
    bool dfs(const string& s, int index, const vector<string>& wordDict,
             vector<int>& dp){

        if(index == s.size()) return true;
        if(dp[index] != -1) return dp[index];

        int left = s.size() - index;
        for(const string& word: wordDict)
            if(left >= word.size() && s.substr(index, word.size()) == word &&
               dfs(s, index + word.size(), wordDict, dp)) return dp[index] = true;
        return dp[index] = false;
    }
};


int main() {

    return 0;
}
