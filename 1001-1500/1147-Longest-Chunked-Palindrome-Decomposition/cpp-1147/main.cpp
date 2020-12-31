/// Source : https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
/// Author : liuyubobobo
/// Time   : 2019-08-03

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {

private:
    string s;

public:
    int longestDecomposition(string text) {

        int n = text.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        s = text;
        return go(0, n - 1, dp);
    }

private:
    int go(int l, int r, vector<vector<int>>& dp){
        if(l > r) return 0;
        if(l == r) return 1;
        if(dp[l][r] != -1) return dp[l][r];

        int len = r - l + 1;
        len /= 2;
        int res = 1;
        for(int ll = 1; ll <= len; ll ++)
            if(s.substr(l, ll) == s.substr(r - ll + 1, ll))
                res = max(res, 2 + go(l + ll, r - ll, dp));
        return dp[l][r] = res;
    }
};


int main() {

    cout << Solution().longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;

    return 0;
}