/// Source : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
/// Author : liuyubobobo
/// Time   : 2020-01-14

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minInsertions(string s) {

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), INT_MAX));
        return dfs(s, 0, s.size() - 1, dp);
    }

private:
    int dfs(const string& s, int a, int b, vector<vector<int>>& dp){

        if(a >= b) return 0;
        if(dp[a][b] != INT_MAX) return dp[a][b];

        int res = INT_MAX;
        if(s[a] == s[b]) res = min(res, dp[a][b] = dfs(s, a + 1, b - 1, dp));
        res = min(res, 1 + min(dfs(s, a + 1, b, dp), dfs(s, a, b - 1, dp)));
        return dp[a][b] = res;
    }
};


int main() {

    cout << Solution().minInsertions("zzazz") << endl;
    // 0

    cout << Solution().minInsertions("mbadm") << endl;
    // 2

    cout << Solution().minInsertions("leetcode") << endl;
    // 5

    return 0;
}
