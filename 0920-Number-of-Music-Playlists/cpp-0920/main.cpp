/// Source : https://leetcode.com/problems/number-of-music-playlists/description/
/// Author : liuyubobobo
/// Time   : 2018-10-06

#include <iostream>
#include <vector>

using namespace std;


/// Combination Mathematic
/// Using inclusive-exclusive theory
///
/// Time Complexity: O((N - K) * L + N * N)
/// Space Complexity: O(N * N)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int numMusicPlaylists(int N, int L, int K) {

        vector<vector<long long>> dp(101, vector<long long>(101, -1ll));

        long long res = num(N, L, K);

        for(int sub = 1; N - sub >= K + 1; sub ++){

            int n = N - sub;
            long long tres = num(n, L, K);
            tres = (tres * C(N, n, dp)) % MOD;

            if(sub % 2){
                res -= tres;
                if(res < 0ll) res += MOD;
            }
            else
                res = (res + tres) % MOD;
        }
        return res;
    }

private:
    long long C(int a, int b, vector<vector<long long>>& dp){

        if(b == 0 || a == b)
            return 1ll;

        if(dp[a][b] != -1ll)
            return dp[a][b];

        return dp[a][b] = (C(a - 1, b, dp) + C(a - 1, b - 1, dp)) % MOD;
    }

    // How many music list can we get to use at most n songs
    int num(int N, int L, int K) {

        long long res = 1ll;
        for(int i = 0; i <= K; i ++)
            res = res * (N - i) % MOD;
        for(int i = K + 1; i < L; i ++)
            res = res * (N - K) % MOD;
        return res;
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