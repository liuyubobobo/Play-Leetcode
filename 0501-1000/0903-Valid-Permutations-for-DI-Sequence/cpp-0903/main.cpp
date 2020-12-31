/// Source : https://leetcode.com/problems/valid-permutations-for-di-sequence/description/
/// Author : liuyubobobo
/// Time   : 2018-09-13

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Memory Search
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
        vector<vector<int>> dp(201, vector<int>(201, -1));
        return go(S, 0, S.size(), dp);
    }

private:
    int go(const string& s, int l, int r, vector<vector<int>>& dp){

        assert(l <= r);
        if(l == r)
            return 1;

        if(dp[l][r] != -1)
            return dp[l][r];

        int res = 0;
        if(s[l] == 'I')
            res = (res + go(s, l + 1, r, dp)) % MOD;
        if(s[r - 1] == 'D')
            res = (res + go(s, l, r - 1, dp)) % MOD;
        for(int i = l + 1; i < r; i ++)
            if(s.substr(i - 1, 2) == "DI"){
                int leftnum = i - l;
                res = (res + ((long long)C[r - l][leftnum] * ((long long)go(s, l, i - 1, dp)) % (long long)MOD
                              * (long long)go(s, i + 1, r, dp)) % (long long)MOD) % MOD;
            }
        return dp[l][r] = res;
    }

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