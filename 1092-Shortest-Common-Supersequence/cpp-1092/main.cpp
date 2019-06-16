/// Source : https://leetcode.com/problems/shortest-common-supersequence/
/// Author : liuyubobobo
/// Time   : 2019-06-15

#include <iostream>
#include <vector>

using namespace std;


/// LCS + Using DP table to reconstruct result
/// Time Complexity: O(|str1| * |str2|)
/// Space Complexity: O(|str1| * |str2|)
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(str1[i] == str2[j])
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                else
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);

//        for(int i = 0; i <= n; i ++){
//            for(int j = 0; j <= m; j ++)
//                cout << dp[i][j] << " ";
//            cout << endl;
//        }
//        cout << dp[n][m] << endl;

        string res = "";
        int cur1 = n, cur2 = m;
        while(cur1 && cur2){
            if(str1[cur1 - 1] != str2[cur2 - 1]){
                if(dp[cur1][cur2] == dp[cur1 - 1][cur2])
                    res += str1[cur1 - 1], cur1 --;
                else
                    res += str2[cur2 - 1], cur2 --;
            }
            else
                res += str1[cur1 - 1], cur1 --, cur2 --;
        }
        while(cur1)
            res += str1[cur1 - 1], cur1 --;
        while(cur2)
            res += str2[cur2 - 1], cur2 --;
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    string str1 = "abac", str2 = "cab";
    cout << Solution().shortestCommonSupersequence(str1, str2) << endl;

    return 0;
}