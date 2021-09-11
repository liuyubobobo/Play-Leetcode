/// Source : https://leetcode.com/problems/valid-parenthesis-string/
/// Author : liuyubobobo
/// Time   : 2021-09-11

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(s, 0, n - 1, dp);
    }

private:
    bool dfs(const string& s, int l, int r, vector<vector<int>>& dp){

        if(l > r) return true;
        if(l == r) return s[l] == '*';
        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] == ')' || s[r] == '(') return dp[l][r] = false;

        if(s[l] == '*' && dfs(s, l + 1, r, dp))
            return dp[l][r] = true;

        if(s[r] == '*' && dfs(s, l, r - 1, dp))
            return dp[l][r] = true;

        if(dfs(s, l + 1, r - 1, dp)) return dp[l][r] = true;

        for(int i = l + 1; i < r; i ++)
            if(dfs(s, l, i, dp) && dfs(s, i + 1, r, dp))
                return dp[l][r] = true;

        return dp[l][r] = false;
    }
};


int main() {

    cout << Solution().checkValidString("()") << endl;
    // 1

    cout << Solution().checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())") << endl;
    // 0

    return 0;
}
