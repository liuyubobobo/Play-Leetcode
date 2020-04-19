/// Source : https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n * m * m * k)
/// Space Complexity: O(n * m * k)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int numOfArrays(int n, int m, int k) {

        int res = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        for(int i = 0; i < m; i ++)
            res = (res + dfs(0, i, k - 1, n, m, dp)) % MOD;
        return res;
    }

private:
    int dfs(int index, int cur_max, int k, int n, int m, vector<vector<vector<int>>>& dp){

        if(index + 1 == n) return k == 0;
        if(dp[index][cur_max][k] != -1) return dp[index][cur_max][k];

        int res = 0;
        for(int i = 0; i < m; i ++)
            if(i <= cur_max) res = (res + dfs(index + 1, cur_max, k, n, m, dp)) % MOD;
            else if(k - 1 >= 0) res = (res + dfs(index + 1, i, k - 1, n, m, dp)) % MOD;
            else break;
        return dp[index][cur_max][k] = res;
    }
};


int main() {

    cout << Solution().numOfArrays(2, 3, 1) << endl;
    // 6

    cout << Solution().numOfArrays(5, 2, 3) << endl;
    // 0

    cout << Solution().numOfArrays(9, 1, 1) << endl;
    // 1

    cout << Solution().numOfArrays(50, 100, 25) << endl;
    // 34549172

    cout << Solution().numOfArrays(37, 17, 7) << endl;
    // 418930126

    return 0;
}
