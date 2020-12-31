/// Source : https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n * m * m * k)
/// Space Complexity: O(n * m * k)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int numOfArrays(int n, int m, int k) {

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        for(int cur_max = 0; cur_max < m; cur_max ++)
            dp[n - 1][cur_max][0] = 1;

        for(int i = n - 2; i >= 0; i --)
            for(int cur_max = 0; cur_max < m; cur_max ++)
                for(int j = 0; j < k; j ++){

                    for(int p = 0; p < m; p ++)
                        if(p <= cur_max)
                            dp[i][cur_max][j] = (dp[i][cur_max][j] + dp[i + 1][cur_max][j]) % MOD;
                        else if(j)
                            dp[i][cur_max][j] = (dp[i][cur_max][j] + dp[i + 1][p][j - 1]) % MOD;
                }

        int res =0;
        for(int x = 0; x < m; x ++)
            res = (res + dp[0][x][k - 1]) % MOD;
        return res;
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
