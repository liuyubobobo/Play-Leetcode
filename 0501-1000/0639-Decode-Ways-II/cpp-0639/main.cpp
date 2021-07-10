/// Source : https://leetcode.com/problems/decode-ways-ii/
/// Author : liuyubobobo
/// Time   : 2021-07-09

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int numDecodings(string s) {

        vector<int> dp(s.size(), -1);
        return dfs(s, 0, dp);
    }

private:
    long long dfs(const string& s, int index, vector<int>& dp){

        if(index == s.size()) return 1ll;
        if(dp[index] != -1) return dp[index];

        if(s[index] == '0') return dp[index] = 0ll;

        long long res = 0ll;
        if(s[index] != '*'){
            res = (res + dfs(s, index + 1, dp)) % MOD;

            if(index + 1 < s.size()){
                if(s[index] == '1')
                    res = (res + (long long)(s[index + 1] == '*' ? 9 : 1) * dfs(s, index + 2, dp)) % MOD;
                else if(s[index] == '2') {
                    if(s[index + 1] == '*')
                        res = (res + 6ll * dfs(s, index + 2, dp)) % MOD;
                    else if(s[index + 1] <= '6')
                        res = (res + dfs(s, index + 2, dp)) % MOD;
                }
            }
        }
        else{ // == '*'
            res = (res + 9ll * dfs(s, index + 1, dp)) % MOD;

            if(index + 1 < s.size()){
                if(s[index + 1] != '*'){
                    if(s[index + 1] <= '6')
                        res = (res + 2ll * dfs(s, index + 2, dp)) % MOD;
                    else
                        res = (res + dfs(s, index + 2, dp)) % MOD;
                }
                else res = (res + 15ll * dfs(s, index + 2, dp)) % MOD;
            }
        }
        return dp[index] = res;
    }
};


int main() {

    cout << Solution().numDecodings("*") << endl;
    // 9

    cout << Solution().numDecodings("1*") << endl;
    // 18

    cout << Solution().numDecodings("2*") << endl;
    // 15

    cout << Solution().numDecodings("**") << endl;
    // 96

    cout << Solution().numDecodings("2839") << endl;
    // 1

    return 0;
}
