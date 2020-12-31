/// Source : https://leetcode.com/problems/count-ways-to-distribute-candies/
/// Author : liuyubobobo
/// Time   : 2020-12-20

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(nk)
/// Space Complexity: O(nk)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int waysToDistribute(int n, int k) {

        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 1ll));
        for(int i = 2; i <= k; i ++)
            for(int j = i + 1; j <= n; j ++)
                dp[i][j] = (dp[i][j - 1] * i + dp[i - 1][j - 1] ) % MOD;
        return dp[k][n];
    }
};


int main() {

    cout << Solution().waysToDistribute(3, 2) << endl;
    // 3

    cout << Solution().waysToDistribute(4, 2) << endl;
    // 6

    cout << Solution().waysToDistribute(20, 5) << endl;
    // 206085257

    return 0;
}
