/// Source : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(|words| * len + len * |target|)
/// Space Complexity: O(|words| * len + len * |target|)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int numWays(vector<string>& words, string target) {

        int len = words[0].size();
        vector<vector<int>> data(len, vector<int>(26, 0));
        for(int i = 0; i < words.size(); i ++)
            for(int j = 0; j < len; j ++) data[j][words[i][j] - 'a'] ++;

        vector<vector<int>> dp(len, vector<int>(target.size(), 0));
        dp[0][0] = data[0][target[0] - 'a'];

        for(int i = 1; i < len; i ++){
            dp[i][0] = (data[i][target[0] - 'a'] + dp[i - 1][0]) % MOD;
            for(int j = 1; j < target.size(); j ++){
                dp[i][j] = (long long)data[i][target[j] - 'a'] * dp[i - 1][j - 1] % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
        return dp[len - 1][target.size() - 1];
    }
};


int main() {

    vector<string> words1 = {"acca","bbbb","caca"};
    cout << Solution().numWays(words1, "aba") << endl;
    // 6

    vector<string> words2 = {"abba","baab"};
    cout << Solution().numWays(words2, "bab") << endl;
    // 4

    vector<string> words3 = {"abcd"};
    cout << Solution().numWays(words3, "abcd") << endl;
    // 1

    vector<string> words4 = {"abab","baba","abba","baab"};
    cout << Solution().numWays(words4, "abba") << endl;
    // 16

    return 0;
}
