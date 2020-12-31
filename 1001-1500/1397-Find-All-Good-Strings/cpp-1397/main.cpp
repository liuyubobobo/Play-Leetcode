/// Source : https://leetcode.com/problems/find-all-good-strings/
/// Author : liuyubobobo
/// Time   : 2020-04-08

#include <iostream>
#include <vector>

using namespace std;


/// Digit DP + KMP
/// Time Complexity: O(n * |evil|)
/// Space Complexity: O(n * |evil|)
class Solution {

private:
    vector<int> lps;
    int MOD = 1e9 + 7;

public:
    int findGoodStrings(int n, string s1, string s2, string evil) {

        lps = getLPS(evil);

        vector<vector<vector<int>>> dp1(n, vector<vector<int>>(evil.size(), vector<int>(2, -1)));
        int a = dfs(0, 0, 1, evil, s1, dp1);
//        cout << "a = " << a << endl;

        vector<vector<vector<int>>> dp2(n, vector<vector<int>>(evil.size(), vector<int>(2, -1)));
        int b = dfs(0, 0, 1, evil, s2, dp2);
//        cout << "b = " << b << endl;

        int res = b - a + (s1.find(evil) == string::npos);
        if(res < 0) res += MOD;
        return res;
    }

private:
    int dfs(int index, int state, int limit, const string& evil, const string& s,
            vector<vector<vector<int>>>& dp){

        if(index == s.size()) return 1;
        if(dp[index][state][limit] != -1) return dp[index][state][limit];

        char bound = limit ? s[index] : 'z';
        int res = 0;
        for(char i = 'a'; i <= bound; i ++){
            if(i == evil[state] && state + 1 == evil.size()) continue;

            int next_state = 0;
            if(i == evil[state]) next_state = state + 1;
            else{
                next_state = state;
                while(next_state){
                    next_state = lps[next_state - 1];
                    if(i == evil[next_state]){
                        next_state ++;
                        break;
                    }
                }
            }

            res += dfs(index + 1, next_state, limit && i == s[index], evil, s, dp);
            res %= MOD;
        }
        return dp[index][state][limit] = res;
    }

    vector<int> getLPS(const string& pattern){

        vector<int> lps(pattern.size(), 0);

        int len = 0;
        for(int i = 1; i < pattern.size(); i ++){
            while(len && pattern[i] != pattern[len])
                len = lps[len - 1];

            if(pattern[i] == pattern[len])
                lps[i] = ++ len;
        }
        return lps;
    }
};


int main() {

    cout << Solution().findGoodStrings(2, "aa", "da", "b") << endl;
    // 51

    cout << Solution().findGoodStrings(8, "leetcode", "leetgoes", "leet") << endl;
    // 0

    cout << Solution().findGoodStrings(2, "gx", "gz", "x") << endl;
    // 2

    cout << Solution().findGoodStrings(8, "pzdanyao", "wgpmtywi", "sdka") << endl;
    // 500543753

    cout << Solution().findGoodStrings(81, "ithrfztwiwvtkyzgufoxtofywlyhwwjdmpfbtyvpqtkitfhhoyhjrmoipdcaaksgfuzaersicuarqbyng",
                                           "uxmmpikhthamnhicxsseiqeeojmdgvchkdbzagbwxovdwdmpmfhosgwksgbzpmjmyeamvbmeojbbeidca",
                                       "uexivgvomkuiiuuhhbszsflntwruqblr");


    return 0;
}
