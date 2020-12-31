/// Source : https://leetcode.com/contest/weekly-contest-58/problems/minimum-window-subsequence/
/// Author : liuyubobobo
/// Time   : 2017-11-12

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

/// Dynamic Programming with Rolling 1-D Array
/// dp[i][j] - the largest start index s for S[s...i] to satify T[0...j]
///
/// Time Complexity: O(len(S)*len(T))
/// Space Complexity: O(len(S))
using namespace std;

class Solution {

private:
    int MY_MAX_INT = 20001;

public:
    string minWindow(string S, string T) {

        if(T.size() == 1 && S.find(T[0]) != string::npos)
            return T;

        vector<vector<int>> dp(2, vector<int>(S.size(), -1));

        dp[0][0] = (S[0] == T[0]) ? 0 : -1;
        for(int j = 1 ; j < S.size() ; j ++)
            dp[0][j] = (S[j] == T[0]) ? j : dp[0][j-1];

        for(int i = 1 ; i < T.size() ; i ++){
            for(int j = 0 ; j < i ; j ++)
                dp[i%2][j] = -1;
            for(int j = i ; j < S.size() ; j ++){
                dp[i%2][j] = dp[i%2][j-1];
                if(T[i] == S[j])
                    dp[i%2][j] = max(dp[(i-1)%2][j-1], dp[i%2][j]);
            }
        }

        int min_length = MY_MAX_INT;
        int start = -1;
        for(int j = T.size() - 1 ; j < S.size() ; j ++)
            if(dp[(T.size()-1)%2][j] != -1){
                int length = j - dp[(T.size()-1)%2][j] + 1;
                assert(length > 0);
                if(length < min_length){
                    min_length = length;
                    start = dp[(T.size()-1)%2][j];
                }
            }
        return (start != -1 && min_length < MY_MAX_INT) ?
               S.substr(start, min_length) : "";
    }
};

int main() {

    string S1 = "abcdebdde";
    string T1 = "bde";
    cout << Solution().minWindow(S1, T1) << endl;
    // bcde

    // ---

    string S2 = "ab";
    string T2 = "b";
    cout << Solution().minWindow(S2, T2) << endl;
    // b

    // ---

    string S3 = "cnhczmccqouqadqtmjjzl";
    string T3 = "mm";
    cout << Solution().minWindow(S3, T3) << endl;
    // mccqouqadqtm

    // ---

    string S4 = "clgkckxqhqojiroohcudeyhlylicvafvpbubcjictifyoshucybzswblioaflxaoxdjbjejvzgqiuedmzgmqbhpkjlwxvobrcgqhzzelxppwdkwqlplflnldxpkwobqyqhqbfcxolrmrllmzpgjemzhscagqxhyuqquopquyyxwcuetxnxebbrgsbiwtkqdpqmvsprrnyficfxagfsssvppwqdsqesz";
    string T4 = "cihfrleqav";
    cout << Solution().minWindow(S4, T4) << endl;
    // cybzswblioaflxaoxdjbjejvzgqiuedmzgmqbhpkjlwxvobrcgqhzzelxppwdkwqlplflnldxpkwobqyqhqbfcxolrmrllmzpgjemzhscagqxhyuqquopquyyxwcuetxnxebbrgsbiwtkqdpqmvsprrnyficfxagfsssv

    return 0;
}