/// Source : https://leetcode.com/problems/count-palindromic-subsequences/description/
/// Author : liuyubobobo
/// Time   : 2022-12-15

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const int D = 10;
    const long long MOD = 1e9 + 7;

public:
    int countPalindromes(string s) {

        int n = s.size();

        vector<vector<int>> pre1(D, vector<int>(n)), suf1(D, vector<int>(n));
        for(char c = 0; c < D; c ++){
            pre1[c][0] = (s[0] - '0' == c);
            for(int i = 1; i < n; i ++)
                pre1[c][i] = pre1[c][i - 1] + (s[i] - '0' == c);

            suf1[c][n - 1] = (s[n - 1] - '0' == c);
            for(int i = n - 2; i >= 0; i --)
                suf1[c][i] = suf1[c][i + 1] + (s[i] - '0' == c);
        }

        vector<vector<vector<int>>> pre2(10, vector<vector<int>>(10, vector<int>(n, 0)));
        vector<vector<vector<int>>> suf2(10, vector<vector<int>>(10, vector<int>(n, 0)));
        for(int i = 1; i < n; i ++){
            // c1, c2, x
            for(char c1 = 0; c1 < D; c1 ++)
                for(char c2 = 0; c2 < D; c2 ++){
                    if(s[i] - '0' == c2) pre2[c2][c1][i] += pre1[c1][i - 1];
                    pre2[c2][c1][i] += pre2[c2][c1][i - 1];
                }
        }
        for(int i = n - 2; i >= 0; i --){
            // x, c1, c2
            for(char c1 = 0; c1 <= 9; c1 ++)
                for(char c2 = 0; c2 <= 9; c2 ++){
                    if(s[i] - '0' == c1) suf2[c1][c2][i] += suf1[c2][i + 1];
                    suf2[c1][c2][i] += suf2[c1][c2][i + 1];
                }
        }

        long long res = 0, MOD = 1e9 + 7;
        for(int i = 2; i < n - 2; i ++){
            // a, b, x, b, a
            for(int a = 0; a < D; a ++)
                for(int b = 0; b < D; b ++)
                    res += (1ll * pre2[b][a][i - 1] * suf2[b][a][i + 1]) % MOD, res %= MOD;
        }
        return res;
    }
};


int main() {

    cout << Solution().countPalindromes("103301") << '\n';
    // 2

    cout << Solution().countPalindromes("0000000") << '\n';
    // 21

    cout << Solution().countPalindromes("9999900000") << '\n';
    // 2

    return 0;
}
