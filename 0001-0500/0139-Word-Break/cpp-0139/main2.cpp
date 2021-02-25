/// Source : https://leetcode.com/problems/word-break/
/// Author : liuyubobobo
/// Time   : 2021-02-25

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(|s| * |wordDict|)
/// Space Complexity: O(|s|)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for(int i = dp.size() - 1; i >= 0; i --){
            int left = s.size() - i;
            for(const string& word: wordDict)
                if(left >= word.size() && s.substr(i, word.size()) == word &&
                   dp[i + word.size()]){
                    dp[i] = true;
                    break;
                }
        }
        return dp[0];
    }
};


int main() {

    return 0;
}
