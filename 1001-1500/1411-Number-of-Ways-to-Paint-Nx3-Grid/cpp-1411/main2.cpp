/// Source : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
/// Author : liuyubobobo
/// Time   : 2020-04-14

#include <iostream>
#include <vector>

using namespace std;


/// State Compression and DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int numOfWays(int n) {

        vector<vector<int>> dp(n, vector<int>(27, 0));
        for(int state = 0; state < 27; state ++){
            int a = state % 3, b = state / 3 % 3, c = state / 9;
            if(a != b && b != c) dp[0][state] = 1;
        }

        for(int i = 1; i < n; i ++)
            for(int state = 0; state < 27; state ++){
                int a = state % 3, b = state / 3 % 3, c = state / 9;
                if(a != b && b != c)
                    for(int state2 = 0; state2 < 27; state2 ++){
                        int a2 = state2 % 3, b2 = state2 / 3 % 3, c2 = state2 / 9;
                        if(a != a2 && b != b2 && c != c2)
                            dp[i][state] += dp[i - 1][state2],
                            dp[i][state] %= MOD;
                    }
            }

        int res = 0;
        for(int state = 0; state < 27; state ++)
            res += dp[n - 1][state], res %= MOD;
        return res;
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
