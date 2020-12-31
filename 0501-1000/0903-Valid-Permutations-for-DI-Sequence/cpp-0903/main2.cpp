/// Source : https://leetcode.com/problems/valid-permutations-for-di-sequence/description/
/// Author : liuyubobobo
/// Time   : 2018-09-13

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Dynamic Programming
/// Put minimum number in interval [l...r]
///
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {

private:
    vector<vector<int>> C;
    const int MOD = 1e9 + 7;

public:
    int numPermsDISequence(string S) {

        calcC();

        vector<vector<int>> dp(201, vector<int>(201, 1));
        for(int len = 3; len <= S.size() + 1; len ++)
            for(int l = 0; l + len - 1 <= S.size(); l ++){
                dp[l][len] = 0;
                if(S[l] == 'I')
                    dp[l][len] = (dp[l][len] + dp[l + 1][len - 1]) % MOD;
                if(S[l + len - 2] == 'D')
                    dp[l][len] = (dp[l][len] + dp[l][len - 1]) % MOD;
                for(int k = l + 1; k < l + len - 1; k ++)
                    if(S.substr(k - 1, 2) == "DI") {
                        int leftnum = k - l;
                        dp[l][len] = (dp[l][len] + (((long long)C[len - 1][leftnum] * (long long)dp[l][leftnum]) % (long long)MOD
                                       * (long long)dp[k + 1][len - leftnum - 1]) % (long long) MOD) % MOD;
                    }
            }
        return dp[0][S.size() + 1];
    }

private:
    void calcC(){
        C.clear();
        for(int i = 0; i <= 200; i ++)
            C.push_back(vector<int>(201, 0));

        for(int i = 0; i <= 200; i ++){
            C[i][0] = 1;
            for(int j = 1; j <= i; j ++)
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
};


int main() {

    cout << Solution().numPermsDISequence("DID") << endl;
    // 5

    cout << Solution().numPermsDISequence("ID") << endl;
    // 2

    return 0;
}