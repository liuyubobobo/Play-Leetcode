/// Source : https://leetcode.com/problems/remove-invalid-parentheses/description/
/// Author : liuyubobobo
/// Time   : 2018-10-12

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;


class Solution {

private:
    int n;

public:
    vector<string> removeInvalidParentheses(string s) {

        n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // index, left - right
        int maxcount = dfs(s, 0, 0, dp);
        cout << maxcount << endl;

        unordered_set<string> res;
        if(maxcount > 0)
            for(int i = 0; i < n; i ++)
                if(dp[i][0] == maxcount)
                    getRes(s, i, 0, "", res, dp);
        if(res.size() == 0)
            res.insert("");
        return vector<string>(res.begin(), res.end());
    }

private:
    void getRes(const string& s, int index, int sub, string tres,
                unordered_set<string>& res, const vector<vector<int>>& dp){

        int cnt = dp[index][sub];
        if(index == n){
            if(cnt == 0)
                res.insert(tres);
            return;
        }

        for(int i = index; i < n; i ++)
            if(s[i] == '(' && dp[i + 1][sub + 1] == cnt - 1)
                getRes(s, i + 1, sub + 1, tres + s[i], res, dp);
            else if(s[i] == ')'){
                if(sub > 0 && dp[i + 1][sub - 1] == cnt - 1)
                    getRes(s, i + 1, sub - 1, tres + s[i], res, dp);
            }
            else if(dp[i + 1][sub] == cnt - 1)
                getRes(s, i + 1, sub, tres + s[i], res, dp);

        if(dp[n][sub] == 0 && cnt == 0)
            getRes(s, n, sub, tres, res, dp);
    }

    int dfs(const string& s, int index, int sub,
            vector<vector<int>>& dp){

        if(index == n)
            return dp[index][sub] = (sub == 0 ? 0 : INT_MIN);

        if(dp[index][sub] != -1)
            return dp[index][sub];

        int res = 0;
        for(int i = index; i < n; i ++)
            if(s[i] == '(')
                res = max(res, 1 + dfs(s, i + 1, sub + 1, dp));
            else if(s[i] == ')'){
                if(sub > 0)
                    res = max(res, 1 + dfs(s, i + 1, sub - 1, dp));
            }
            else
                res = max(res, 1 + dfs(s, i + 1, sub, dp));
        return dp[index][sub] = res;
    }
};


void print_vec(const vector<string>& vec){

    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string s1 = "()())()";
    print_vec(Solution().removeInvalidParentheses(s1));
    // 6
    // (())() ()()()

    string s2 = "(a)())()";
    print_vec(Solution().removeInvalidParentheses(s2));
    // 7
    // (a())() (a)()()

    string s3 = ")(";
    print_vec(Solution().removeInvalidParentheses(s3));
    // 0

    string s4 = "n";
    print_vec(Solution().removeInvalidParentheses(s4));
    // 1
    // n

    string s5 = "x(";
    print_vec(Solution().removeInvalidParentheses(s5));
    // 1
    // x

    return 0;
}