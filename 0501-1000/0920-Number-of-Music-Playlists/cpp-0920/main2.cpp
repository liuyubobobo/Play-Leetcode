/// Source : https://leetcode.com/problems/number-of-music-playlists/description/
/// Author : liuyubobobo
/// Time   : 2018-10-07

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(L * N)
/// Space Complexity: O(L * N)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int numMusicPlaylists(int N, int L, int K) {

        vector<vector<long long>> dp(L + 1, vector<long long>(N + 1, -1ll));
        return dfs(L, N, K, N, dp);
    }

private:
    long long dfs(int l, int n, int K, int N,
                  vector<vector<long long>>& dp) {

        if(n == 0 && l == 0)
            return 1;

        if(n == 0 || l == 0)
            return 0;

        if(dp[l][n] != -1) return dp[l][n];

        return dp[l][n] = ((dfs(l - 1, n - 1, K, N, dp) * (N - n + 1)) % MOD +
                           (dfs(l - 1, n, K, N, dp) * max(n - K, 0)) % MOD) % MOD;
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