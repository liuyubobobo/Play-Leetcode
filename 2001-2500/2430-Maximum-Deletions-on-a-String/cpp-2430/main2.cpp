/// Source : https://leetcode.com/problems/maximum-deletions-on-a-string/
/// Author : liuyubobobo
/// Time   : 2022-10-02

#include <iostream>
#include <vector>

using namespace std;


/// Double DP
/// It's slower than using RK but this method is more standard.
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int deleteString(string s) {

        int n = s.size();

        vector<vector<int>> lcs(n + 1, vector<int>(n + 1, 0));
        for(int i = n - 1; i >= 0; i --)
            for(int j = n - 1; j >= 0; j --)
                if(s[i] == s[j]) lcs[i][j] = 1 + lcs[i + 1][j + 1];

        vector<int> dp(n + 1, 0);
        dp[n - 1] = 1;
        for(int start = n - 2; start >= 0; start --){
            int len = n - start, tres = 1;
            for(int i = 1; i <= len / 2; i ++)
                if(lcs[start][start + i] >= i)
                    tres = max(tres, 1 + dp[start + i]);
            dp[start] = tres;
        }
        return dp[0];
    }
};


int main() {

    string s2 = "aaabaab";
    cout << Solution().deleteString(s2) << '\n';
    // 4

    return 0;
}
