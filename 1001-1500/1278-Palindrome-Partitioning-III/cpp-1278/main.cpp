/// Source : https://leetcode.com/problems/palindrome-partitioning-iii/
/// Author : liuyubobobo
/// Time   : 2021-01-30

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexiity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {

private:
    const int INF = 1e9;
    int n;

public:
    int palindromePartition(string s, int k) {

        n = s.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++) table[i][i] = 0;
        for(int i = 0; i + 1 < n; i ++) table[i][i + 1] = (s[i] != s[i + 1]);
        for(int sz = 3; sz <= n; sz ++)
            for(int i = 0; i + sz <= n; i ++)
                table[i][i + sz - 1] = (s[i] != s[i + sz - 1]) + table[i + 1][i + sz - 2];

        vector<vector<int>> dp(n, vector<int>(k + 1, INF));
        return dfs(s, 0, k, table, dp);
    }

private:
    int dfs(const string& s, int index, int k, const vector<vector<int>>& table,
            vector<vector<int>>& dp){

        if(index == n) return k == 0 ? 0 : INF;
        if(k <= 0) return INF;
        if(dp[index][k] != INF) return dp[index][k];

        int res = INF;
        for(int end = index; n - end >= k; end ++)
            res = min(res, table[index][end] + dfs(s, end + 1, k - 1, table, dp));
        return dp[index][k] = res;
    }
};


int main() {

    cout << Solution().palindromePartition("abc", 2) << endl;
    // 1

    cout << Solution().palindromePartition("aabbc", 3) << endl;
    // 0

    cout << Solution().palindromePartition("leetcode", 8) << endl;
    // 0

    cout << Solution().palindromePartition("faaglagedtwnejzpuarkgwgoefwra", 27) << endl;
    // 0

    return 0;
}
