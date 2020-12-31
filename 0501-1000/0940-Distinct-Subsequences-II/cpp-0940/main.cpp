/// Source : https://leetcode.com/problems/distinct-subsequences-ii/
/// Author : liuyubobobo
/// Time   : 2018-11-12

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int distinctSubseqII(string S) {

        int n = S.size();
        vector<int> dp(n + 1, 1), last(26, -1);

        dp[0] = 1;
        for(int i = 0; i < n; i ++){
            dp[i + 1] = 2 * dp[i] % MOD;
            if(last[S[i] - 'a'] != -1){
                dp[i + 1] -= dp[last[S[i] - 'a']];
                if(dp[i + 1] < 0)
                    dp[i + 1] += MOD;
            }
            last[S[i] - 'a'] = i;
        }
        return dp[n] - 1 < 0 ? MOD - 1 : dp[n] - 1;
    }
};


int main() {

    string s1 = "abc";
    cout << Solution().distinctSubseqII(s1) << endl;
    // 7

    string s2 = "aba";
    cout << Solution().distinctSubseqII(s2) << endl;
    // 6

    string s3 = "aaa";
    cout << Solution().distinctSubseqII(s3) << endl;
    // 3

    string s4 = "cdce";
    cout << Solution().distinctSubseqII(s4) << endl;
    // 13

    string s5 = "lee";
    cout << Solution().distinctSubseqII(s5) << endl;
    // 5

    string s6 = "bcbbca";
    cout << Solution().distinctSubseqII(s6) << endl;
    // 35

    return 0;
}