/// Source : https://leetcode.com/problems/interleaving-string/
/// Author : liuyubobobo
/// Time   : 2021-06-03

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(|s1| * |s2|)
/// Space Complexity: O(|s1| * |s2|)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n1 = s1.size(), n2 = s2.size();
        if(s3.size() != n1 + n2) return false;

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        return dfs(s1, s2, s3, 0, 0, dp);
    }

private:
    int dfs(const string& s1, const string& s2, const string& s3, int i, int j,
            vector<vector<int>>& dp){

        if(i == s1.size() && j == s2.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        if(i == s1.size())
            return dp[i][j] = (s2[j] == s3[i + j] ? dfs(s1, s2, s3, i, j + 1, dp) : 0);

        if(j == s2.size())
            return dp[i][j] = (s1[i] == s3[i + j] ? dfs(s1, s2, s3, i + 1, j, dp) : 0);

        if(s1[i] == s3[i + j] && dfs(s1, s2, s3, i + 1, j, dp) == 1)
            return dp[i][j] = 1;

        if(s2[j] == s3[i + j] && dfs(s1, s2, s3, i, j + 1, dp) == 1)
            return dp[i][j] = 1;

        return dp[i][j] = 0;
    }
};


int main() {

    return 0;
}
