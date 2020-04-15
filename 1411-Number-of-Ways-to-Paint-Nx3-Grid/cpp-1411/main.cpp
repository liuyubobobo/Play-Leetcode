/// Source : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
/// Author : liuyubobobo
/// Time   : 2020-04-11

#include <iostream>
#include <vector>

using namespace std;


/// State Compression and Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int numOfWays(int n) {

        vector<vector<int>> dp(n, vector<int>(27, -1));

        int res = 0;
        for(int i = 0; i < 27; i ++){
            int a = i % 3, b = i / 3 % 3, c = i / 9;
            if(a != b && b != c)
                res += dfs(1, i, n, dp), res %= MOD;
        }
        return res;
    }

private:
    int dfs(int index, int state, int n, vector<vector<int>>& dp){

        if(index == n) return 1;
        if(dp[index][state] != -1) return dp[index][state];

        int a = state % 3, b = state / 3 % 3, c = state / 9;

        int res = 0;
        for(int i = 0; i < 27; i ++){
            int a2 = i % 3, b2 = i / 3 % 3, c2 = i / 9;
            if(a2 != a && b2 != b && c2 != c && a2 != b2 && b2 != c2)
                res += dfs(index + 1, i, n, dp), res %= MOD;
        }
        return dp[index][state] = res;
    }
};


int main() {

    cout << Solution().numOfWays(2) << endl;
    // 54

    cout << Solution().numOfWays(3) << endl;
    // 246

    cout << Solution().numOfWays(7) << endl;
    // 106494

    cout << Solution().numOfWays(5000) << endl;
    // 30228214

    return 0;
}
