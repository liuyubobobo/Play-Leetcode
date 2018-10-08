/// Source : https://leetcode.com/problems/number-of-music-playlists/description/
/// Author : liuyubobobo
/// Time   : 2018-10-07

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(L * N)
/// Space Complexity: O(L * N)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int numMusicPlaylists(int N, int L, int K) {

        vector<vector<long long>> dp(L + 1, vector<long long>(N + 1, 0ll));
        dp[0][0] = 1ll;
        for(int i = 1; i <= L; i ++)
            for(int j = 1; j <= N; j ++){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (N - j + 1) % MOD) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j] * max(j - K, 0) % MOD) % MOD;
            }
        return dp[L][N];
    }
};


int main() {

    cout << Solution().numMusicPlaylists(3, 3, 1) << endl;
    // 6

    cout << Solution().numMusicPlaylists(2, 3, 0) << endl;
    // 6

    cout << Solution().numMusicPlaylists(2, 3, 1) << endl;
    // 2

    cout << Solution().numMusicPlaylists(3, 3, 0) << endl;
    // 6

    return 0;
}