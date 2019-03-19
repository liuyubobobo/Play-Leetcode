/// Source : https://leetcode.com/problems/regular-expression-matching/
/// Author : liuyubobobo
/// Time   : 2019-03-19

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(s * p)
/// Space Complexity: O(s * p)
class Solution {
public:
    bool isMatch(const string& s, const string& p) {

        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return match(s, 0, p, 0, dp);
    }

private:
    bool match(const string& s, int sl, const string& p, int pl,
               vector<vector<int>>& dp){

        if(sl == s.size()) return no_more_match(p, pl);
        if(pl == p.size()) return false;

        if(dp[sl][pl] != -1) return dp[sl][pl];

        if(pl + 1 < p.size() && p[pl + 1] == '*'){
            if(s[sl] == p[pl] || p[pl] == '.')
                return dp[sl][pl] = (match(s, sl + 1, p, pl, dp) || match(s, sl, p, pl + 2, dp));
            else
                return dp[sl][pl] = match(s, sl, p, pl + 2, dp);
        }
        else if(s[sl] == p[pl] || p[pl] == '.')
            return dp[sl][pl] = match(s, sl + 1, p, pl + 1, dp);
        return dp[sl][pl] = false;
    }

    bool no_more_match(const string& p, int pl){
        int i;
        for(i = pl; i < p.size(); i += 2)
            if(i + 1 < p.size() && p[i + 1] != '*') return false;
        return i == p.size();
    }
};


int main() {

    cout << Solution().isMatch("aa", "a") << endl; // false
    cout << Solution().isMatch("aa", "a*") << endl; // true
    cout << Solution().isMatch("ab", ".*") << endl; // true
    cout << Solution().isMatch("aab", "c*a*b") << endl; // true
    cout << Solution().isMatch("mississippi", "mis*is*p*") << endl; // false
    cout << Solution().isMatch("ab", ".*c") << endl; // false
    cout << Solution().isMatch("a", ".*..a") << endl; // false
    cout << Solution().isMatch("", ".*") << endl; // true

    return 0;
}