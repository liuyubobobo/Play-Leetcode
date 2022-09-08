/// Source : https://leetcode.com/problems/minimum-time-to-kill-all-monsters/
/// Author : liuyubobobo
/// Time   : 2022-09-07

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(2^n * n)
/// Space Complexity: O(2^n)
class Solution {
public:
    long long minimumTime(vector<int>& power) {

        int n = power.size();

        vector<long long> dp(1 << n, -1);
        return dfs(n, power, 0, dp);
    }

private:
    long long dfs(int n, const vector<int>& power, int state,
                  vector<long long>& dp){

        if(state + 1 == (1 << n)) return 0;
        if(dp[state] != -1) return dp[state];

        long long gain = __builtin_popcount(state) + 1;
        long long res = LONG_LONG_MAX;
        for(int i = 0; i < n; i ++){
            if((state >> i) & 1) continue;
            long long days = power[i] / gain + !!(power[i] % gain);
            res = min(res, days + dfs(n, power, state | (1 << i), dp));
        }
        return dp[state] = res;
    }
};


int main() {

    return 0;
}
