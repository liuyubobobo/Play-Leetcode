/// Source : https://leetcode.com/problems/number-of-ways-to-select-buildings/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long numberOfWays(string s) {

        int n = s.size();
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(4, vector<long long>(n, -1)));
        return dfs(n, s, 0, 3, 0, dp) + dfs(n, s, 1, 3, 0, dp);
    }

private:
    long long dfs(int n, const string& s, int select, int left, int index,
                  vector<vector<vector<long long>>>& dp){

        if(left == 0) return 1;
        if(index == n) return 0;
        if(dp[select][left][index] != -1) return dp[select][left][index];

        long long res = dfs(n, s, select, left, index + 1, dp);
        if(s[index] == (char)('0' + select))
            res += dfs(n, s, 1 - select, left - 1, index + 1, dp);
        return dp[select][left][index] = res;
    }
};


int main() {

    return 0;
}
