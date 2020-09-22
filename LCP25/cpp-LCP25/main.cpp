/// Source : https://leetcode-cn.com/problems/Uh984O/
/// Author : liuyubobobo
/// Time   : 2020-09-21

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Memory Search
/// State: dp[27][27][27][27][27]
/// Time Complexity: O(27**k)
/// Space Complexity: O(27**k)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int keyboard(int k, int n) {

        vector<int> cnt(5, 0);
        cnt[k - 1] = 26;

        unordered_map<int, int> dp;
        return dfs(n, cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], dp);
    }

    long long dfs(int n, int p1, int p2, int p3, int p4, int p5,
            unordered_map<int, int>& dp){

        if(n == 0) return 1;

        int hash = (((p1 * 27 + p2) * 27 + p3) * 27 + p4) * 27 + p5;
        if(dp.count(hash)) return dp[hash];

//        cout << n << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << endl;

        long long res = 0ll;
        if(p1) res += dfs(n - 1, p1 - 1, p2, p3, p4, p5, dp) * p1, res %= MOD;
        if(p2) res += dfs(n - 1, p1 + 1, p2 - 1, p3, p4, p5, dp) * p2, res %= MOD;
        if(p3) res += dfs(n - 1, p1, p2 + 1, p3 - 1, p4, p5, dp) * p3, res %= MOD;
        if(p4) res += dfs(n - 1, p1, p2, p3 + 1, p4 - 1, p5, dp) * p4, res %= MOD;
        if(p5) res += dfs(n - 1, p1, p2, p3, p4 + 1, p5 - 1, dp) * p5, res %= MOD;
        return dp[hash] = res;
    }
};


int main() {

    cout << Solution().keyboard(1, 1) << endl;
    // 26

    cout << Solution().keyboard(1, 2) << endl;
    // 650

    cout << Solution().keyboard(1, 26) << endl;
    // 459042011

    cout << Solution().keyboard(2, 1) << endl;
    // 26

    cout << Solution().keyboard(2, 2) << endl;
    // 676

    cout << Solution().keyboard(5, 50) << endl;
    // 363766962

    return 0;
}
