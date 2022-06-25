/// Source : https://leetcode.com/problems/number-of-distinct-roll-sequences/
/// Author : liuyubobobo
/// Time   : 2022-06-25

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int distinctSequences(int n) {

        if(n == 1) return 6;

        vector<vector<vector<long long>>> dp(7, vector<vector<long long>>(7, vector<long long>(n, 0)));
        for(int cur = 1; cur <= 6; cur ++) dp[0][cur][0] = 1;

        for(int cur = 1; cur <= 6; cur ++)
            for(int pre = 1; pre <= 6; pre ++)
                if(gcd(pre, cur) == 1 && cur != pre) dp[pre][cur][1] += dp[0][pre][0];

        for(int i = 2; i < n; i ++){
            for(int cur = 1; cur <= 6; cur ++){
                for(int p1 = 1; p1 <= 6; p1 ++)
                    for(int p2 = 1; p2 <= 6; p2 ++){
                        if(gcd(p2, cur) == 1 && cur != p2 && cur != p1)
                            dp[p2][cur][i] += dp[p1][p2][i - 1];
                        dp[p2][cur][i] %= MOD;
                    }
            }
        }

        long long res = 0;
        for(int p = 1; p <= 6; p ++)
            for(int cur = 1; cur <= 6; cur ++)
                res += dp[p][cur][n - 1];
        return res % MOD;
    }

private:
    int gcd(int a, int b){
        if(a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    cout << Solution().distinctSequences(2) << '\n';

    cout << Solution().distinctSequences(4) << '\n';

    return 0;
}
