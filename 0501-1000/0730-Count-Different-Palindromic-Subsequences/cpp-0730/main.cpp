/// Source : https://leetcode.com/problems/count-different-palindromic-subsequences/
/// Author : liuyubobobo
/// Time   : 2022-06-09

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int countPalindromicSubsequences(const string& s) {

        int n = s.size();

        vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(n, vector<long long>(n, 0)));
        for(int i = 0; i < n; i ++) dp[s[i] - 'a'][i][i] = 1;
        for(int i = 0; i + 1 < n; i ++){
            if(s[i] == s[i + 1]) dp[s[i] - 'a'][i][i + 1] = 2;
            else{
                dp[s[i] - 'a'][i][i + 1] = dp[s[i + 1] - 'a'][i][i + 1] = 1;
            }
        }

        for(int len = 3; len <= n; len ++){
            for(int l = 0; l + len - 1 < n; l ++){
                int r = l + len - 1;

                for(char border = 0; border < 4; border ++){
                    if(s[l] == s[r] && s[l] == 'a' + border){
                        dp[border][l][r] = 2;
                        for(char c = 0; c < 4; c ++)
                            dp[border][l][r] += dp[c][l + 1][r - 1];
                        dp[border][l][r] %= MOD;
                    }
                    else{
                        dp[border][l][r] = dp[border][l][r - 1] + dp[border][l + 1][r] - dp[border][l + 1][r - 1] + MOD;
                        dp[border][l][r] %= MOD;
                    }
                }
            }
        }

        long long res = 0;
        for(int border = 0; border < 4; border ++)
            res += dp[border][0][n - 1];
        return res % MOD;
    }
};


int main() {

    cout << Solution().countPalindromicSubsequences("bccb") << '\n';
    // 6

    cout << Solution().countPalindromicSubsequences("abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba") << '\n';
    // 104860361

    cout << Solution().countPalindromicSubsequences("baccdabbccbdbbbcdbbcdbacdabaaddcdbcabdbddadbdaaadbbdaabbdaccdabbddaaccdbbcdbcdbbaaababdddbdccbbaddabdbdabddbaccddabaccadacddbbbdacacaaddaccbabcbcbbcbcadccbccddcddccdabdabaddacdcdcbdadabbcddacbbbbacbcadbccacddddacbdcddbddbddbcabcbdacadbdccabddaacadddbadbccdacbaabababcababccddacabadbcaacbadcbacaadabbadabaabdbcabdabaddabdcacbdbacbcdcacdcaaccadabacbadcdabddccaaacdaadacbbcadcbbccaccbbbdcbcaabbbddcdaaddbdbbdacdaabacbacdabbbdbdaaddbddadbabcdabaddbbadcaadcddcaaddcdbbbbddcccaacdbdbcccccddadbacbdbcacabddaabcbbbbcadbbcabbabcbcdccdcaddabbbddbbdadbbbdadbbdaaacbbbbdbbcadcbbcddddcacdcbddcaacbaccacaddcdacbadccaabdabadbbcccabddcbbcdaacddaacccbacccacbddbcdcdaabbbacdcbabaaaaaacdabcddbcbaccabacddaccadaaddddaaaccbccdbdcdcdbdccdcbdbddbcdbcbdaacaccdabdbabcdbdbadcbcbbaabaccbbababdbbddbcacadbaaadbcccadaddbccddbcadaccbaddcdacaabbbbdbcddacbdccddaadabbbaccddbcbacbbbcbbbbcbbccdbaccdddaddaaacdababcdabdacdbaacdadbaabcadcddccabcccadabbdbbadbcadbdbaddaabbbcdbbbddcdbddbabcdccddccbaccbabcdcddddabbabdccbaddccacdddadcaadd") << endl;

    return 0;
}
