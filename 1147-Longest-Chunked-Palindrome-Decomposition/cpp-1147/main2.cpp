/// Source : https://leetcode.com/problems/longest-chunked-palindrome-decomposition/
/// Author : liuyubobobo
/// Time   : 2019-08-04

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Space Optimized
///
/// Time Complexity: O(n^3)
/// Space Complexity: O(n)
class Solution {

private:
    string s;
    int n;

public:
    int longestDecomposition(string text) {

        n = text.size();
        vector<int> dp(n, -1);
        s = text;
        return go(0, dp);
    }

private:
    int go(int l, vector<int>& dp){
        if(n % 2){
            if(l == n / 2) return 1;
            if(l > n /2 ) return 0;
        }
        else if(l >= n / 2) return 0;

        if(dp[l] != -1) return dp[l];

        int res = 1;
        for(int len = 1; l + len <= n / 2; len ++)
            if(s.substr(l, len) == s.substr(n - l - len, len))
                res = max(res, 2 + go(l + len, dp));
        return dp[l] = res;
    }
};


int main() {

    cout << Solution().longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;
    cout << Solution().longestDecomposition("aaa") << endl;

    return 0;
}