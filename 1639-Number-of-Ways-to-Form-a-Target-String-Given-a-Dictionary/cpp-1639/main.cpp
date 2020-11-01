/// Source : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
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

        vector<vector<int>> dp(len, vector<int>(target.size(), -1));
        return dfs(data, target, 0, 0, dp);
    }

private:
    int dfs(const vector<vector<int>>& data, const string& target, int di, int ti,
            vector<vector<int>>& dp){

        if(ti == target.size()) return 1;
        if(di == data.size()) return 0;
        if(dp[di][ti] != -1) return dp[di][ti];

        int res = (long long)data[di][target[ti] - 'a'] * dfs(data, target, di + 1, ti + 1, dp) % MOD;
        res = res + dfs(data, target, di + 1, ti, dp);
        return dp[di][ti] = res % MOD;
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
