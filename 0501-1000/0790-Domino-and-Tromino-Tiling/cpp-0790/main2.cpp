/// Source : https://leetcode.com/problems/domino-and-tromino-tiling/description/
/// Author : liuyubobobo
/// Time   : 2018-03-07

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
///
/// dp[i][0]: how many ways to fill a 2*(i-1) tiles plus:
/// .....0
/// .....0
///
/// dp[i][1]: how many ways to fill a 2*(i-1) tiles plus:
/// .....1
/// .....0
///
/// dp[i][2]: how many ways to fill a 2*(i-1) tiles plus:
/// .....0
/// .....1
///
/// dp[i][3]: how many ways to fill a 2*(i-1) tiles plus:
/// .....1
/// .....1
///
/// The answer is dp[N][3]
///
/// Time Complexity: O(N)
/// Space Complexity: O(N)
class Solution {

public:
    int numTilings(int N) {

        vector<vector<int>> res(N+1, vector<int>(4, 0));

        res[0][0] = 0;
        res[0][1] = 0;
        res[0][2] = 0;
        res[0][3] = 1;

        int mod = 1000000007;
        for(int i = 1 ; i <= N ; i ++){

            res[i][0] = res[i-1][3];
            res[i][1] = (res[i-1][0] + res[i-1][2]) % mod;
            res[i][2] = (res[i-1][0] + res[i-1][1]) % mod;
            res[i][3] = 0;
            for(int j = 0 ; j < 4 ; j ++)
                res[i][3] = (res[i][3] + res[i-1][j]) % mod;

            // cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << res[i][3] << endl;
        }

        return res[N][3];
    }
};

int main() {

    cout << Solution().numTilings(3) << endl; // 5
    cout << Solution().numTilings(4) << endl; // 11
    cout << Solution().numTilings(7) << endl; // 117
    cout << Solution().numTilings(1000) << endl; // 979232805

    return 0;
}