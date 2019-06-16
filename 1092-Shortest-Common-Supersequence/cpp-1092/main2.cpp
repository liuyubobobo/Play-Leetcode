/// Source : https://leetcode.com/problems/shortest-common-supersequence/
/// Author : liuyubobobo
/// Time   : 2019-06-16

#include <iostream>
#include <vector>

using namespace std;


/// LCS + Using LCS string to reconstruct
/// Time Complexity: O(|str1| * |str2|)
/// Space Complexity: O(|str1| * |str2|)
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size(), m = str2.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));

        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(str1[i] == str2[j])
                    dp[i + 1][j + 1] = dp[i][j] + str1[i];
                else
                    dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?
                                       dp[i + 1][j] : dp[i][j + 1];
        string lcs = dp[n][m];
//        cout << lcs << endl;

        string res = "";
        int cur1 = 0, cur2 = 0;
        for(char c: lcs){
            while(cur1 < n && str1[cur1] != c)
                res += str1[cur1 ++];
            while(cur2 < m && str2[cur2] != c)
                res += str2[cur2 ++];
            res += c, cur1 ++, cur2 ++;
        }
        return res + str1.substr(cur1) + str2.substr(cur2);
    }
};


int main() {

    string str1 = "abac", str2 = "cab";
    cout << Solution().shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}