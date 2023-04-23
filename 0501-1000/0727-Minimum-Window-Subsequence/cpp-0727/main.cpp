/// Source : https://leetcode.com/contest/weekly-contest-58/problems/minimum-window-subsequence/
/// Author : liuyubobobo
/// Time   : 2017-11-12
/// Updated: 2023-04-22

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;


/// Dynamic Programming with Rolling 1-D Array
/// dp[i][j] - the minimum length W for subsequence in S[i...end) to satify T[j...end)
/// the result is the minimum value for all dp[i][0] where len(S[i...end)) > len(T)
///
/// Time Complexity: O(len(S)*len(T))
/// Space Complexity: O(len(T))
class Solution {

private:
    int MY_MAX_INT = 20001;

public:
    string minWindow(string S, string T) {

        vector<vector<int>> dp(2, vector<int>(T.size(), MY_MAX_INT));

        int min_length = MY_MAX_INT;
        int start = -1;

        dp[(S.size()-1)%2][T.size()-1] = (S.back() == T.back() ? 1 : MY_MAX_INT);
        if(dp[(S.size()-1)%2][0] == 1 && T.size() == 1){
            min_length = 1;
            start = S.size()-1;
        }
        else
            for(int j = T.size()-2 ; j >= 0 ; j --)
                dp[(S.size()-1)%2][j] = MY_MAX_INT;

        for(int i = S.size()-2 ; i >= 0 ; i --){
            dp[i%2][T.size()-1] = dp[(i+1)%2][T.size()-1] + 1;
            if(S[i] == T.back())
                dp[i%2][T.size()-1] = 1;

            for(int j = T.size() - 2 ; j >= 0 ; j --){
                dp[i%2][j] = min(MY_MAX_INT, 1 + dp[(i+1)%2][j]);
                if(S[i] == T[j])
                    dp[i%2][j] = min(dp[i%2][j], 1 + dp[(i+1)%2][j+1]);
            }

            if(i + T.size() <= S.size() && dp[i%2][0] <= min_length){
                min_length = dp[i%2][0];
                start = i;
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

    string S2 = "ab";
    string T2 = "b";
    cout << Solution().minWindow(S2, T2) << endl;
    // b

    string S3 = "cnhczmccqouqadqtmjjzl";
    string T3 = "mm";
    cout << Solution().minWindow(S3, T3) << endl;
    // mccqouqadqtm

    string S4 = "clgkckxqhqojiroohcudeyhlylicvafvpbubcjictifyoshucybzswblioaflxaoxdjbjejvzgqiuedmzgmqbhpkjlwxvobrcgqhzzelxppwdkwqlplflnldxpkwobqyqhqbfcxolrmrllmzpgjemzhscagqxhyuqquopquyyxwcuetxnxebbrgsbiwtkqdpqmvsprrnyficfxagfsssvppwqdsqesz";
    string T4 = "cihfrleqav";
    cout << Solution().minWindow(S4, T4) << endl;
    // cybzswblioaflxaoxdjbjejvzgqiuedmzgmqbhpkjlwxvobrcgqhzzelxppwdkwqlplflnldxpkwobqyqhqbfcxolrmrllmzpgjemzhscagqxhyuqquopquyyxwcuetxnxebbrgsbiwtkqdpqmvsprrnyficfxagfsssv

    string S5 = "aaa";
    string T5 = "aaaaaaaa";
    cout << Solution().minWindow(S5, T5) << endl;
    // mccqouqadqtm

    return 0;
}