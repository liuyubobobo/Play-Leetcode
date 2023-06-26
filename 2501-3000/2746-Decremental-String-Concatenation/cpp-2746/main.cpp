/// Source : https://leetcode.com/problems/decremental-string-concatenation/description/
/// Author : liuyubobobo
/// Time   : 2023-06-25

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Memoization
/// Time Complexity: O(n * 26^2)
/// Space Complexity: O(n * 26^2)
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {

        int n = words.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(26, vector<int>(26, -1)));
        return (int)words[0].size() + dfs(words, 1, words[0][0] - 'a', words[0].back() - 'a', dp);
    }

private:
    int dfs(const vector<string>& words, int index, int front, int tail,
            vector<vector<vector<int>>>& dp){

        if(index == words.size()) return 0;
        if(dp[index][front][tail] != -1) return dp[index][front][tail];

        int res = INT_MAX;
        if(words[index].back() - 'a' == front)
            res = min(res, (int)words[index].size() - 1 + dfs(words, index + 1, words[index][0] - 'a', tail, dp));
        else
            res = min(res, (int)words[index].size() + dfs(words, index + 1, words[index][0] - 'a', tail, dp));

        if(words[index][0] - 'a' == tail)
            res = min(res, (int)words[index].size() - 1 + dfs(words, index + 1, front, words[index].back() - 'a', dp));
        else
            res = min(res, (int)words[index].size() + dfs(words, index + 1, front, words[index].back() - 'a', dp));

        return dp[index][front][tail] = res;
    }
};


int main() {

    return 0;
}
