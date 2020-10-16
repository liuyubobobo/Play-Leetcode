/// Source : https://leetcode.com/problems/strange-printer/
/// Author : liuyubobobo
/// Time   : 2020-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Interval DP
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int strangePrinter(string s) {

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return dfs(s, 0, s.size() - 1, dp);
    }

private:
    int dfs(const string& s, int l, int r, vector<vector<int>>& dp){

        if(l > r) return 0;
        if(l == r) return 1;

        if(dp[l][r] != -1) return dp[l][r];

        int res = 1 + dfs(s, l + 1, r, dp);
        for(int i = l + 1; i <= r; i ++)
            if(s[i] == s[l])
                res = min(res, dfs(s, l, i - 1, dp) + dfs(s, i + 1, r, dp));
        return dp[l][r] = res;
    }
};


int main() {

    cout << Solution().strangePrinter("aaabbb") << endl;
    // 2

    cout << Solution().strangePrinter("aba") << endl;
    // 2

    cout << Solution().strangePrinter("aaaaaaaaaaaaaaaaaaaaa") << endl;
    // 1

    cout << Solution().strangePrinter("baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa") << endl;
    // 19

    cout << Solution().strangePrinter("dddccbdbababaddcbcaabdbdddcccddbbaabddb") << endl;
    // 15

    return 0;
}
