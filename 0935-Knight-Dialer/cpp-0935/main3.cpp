/// Source : https://leetcode.com/problems/knight-dialer/
/// Author : liuyubobobo
/// Time   : 2018-11-03

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Dynamic Programming
/// Space Optimized
///
/// Time Complexity: O(10 * N)
/// Space Complexity: O(2 * 10)
class Solution {

private:
    int MOD = 1e9 + 7;
    const vector<vector<int>> trans = {
            {4, 6}, // 0
            {6, 8}, // 1
            {7, 9}, // 2
            {4, 8}, // 3
            {3, 9, 0}, // 4
            {}, // 5
            {1, 7, 0}, // 6
            {2, 6}, // 7
            {1, 3}, // 8
            {2, 4}  // 9
    };

public:
    int knightDialer(int N) {

        if(N == 1)
            return 10;

        vector<vector<int>> dp(2, vector<int>(10, 0));
        for(int j = 0; j < 10; j ++)
            dp[0][j] = 1;

        for(int i = 1; i < N; i ++){
            fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
            for(int j = 0; j < 10; j ++)
                for(int next: trans[j])
                    dp[i & 1][next] = (dp[i & 1][next] + dp[(i - 1) & 1][j]) % MOD;
        }

        int res = 0;
        for(int j = 0; j < 10; j ++)
            res = (res + dp[(N - 1) & 1][j]) % MOD;
        return res;
    }
};


int main() {

    cout << Solution().knightDialer(1) << endl;
    // 10

    cout << Solution().knightDialer(2) << endl;
    // 20

    cout << Solution().knightDialer(3) << endl;
    // 46

    cout << Solution().knightDialer(4) << endl;
    // 104

    cout << Solution().knightDialer(18) << endl;
    // 11208704

    return 0;
}