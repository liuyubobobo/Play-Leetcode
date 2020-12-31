/// Source : https://leetcode.com/problems/dice-roll-simulation/
/// Author : liuyubobobo
/// Time   : 2019-10-12

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search - State Compression
/// Time Complexity: O(n * 6 * max(rollMax) * 6)
/// Space Complexity: O(n * 6 * max(rollMax))
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int dieSimulator(int n, vector<int>& rollMax) {

        vector<int> dp(1600000, -1);
        int res = 0;
        for(int i = 0; i < 6; i ++)
            res = (res + dfs(n, 100000 + i * 10000 + 1, rollMax, dp))% MOD;
        return res;
    }

private:
    int dfs(int n, int state, const vector<int>& rollMax, vector<int>& dp){

        if(dp[state] != -1) return dp[state];

        int index = state % 10000;
        if(index == n) return 1;

        int lastnum = state / 10000 % 10;
        int lastfreq = state / 100000;
        int res = 0;
        for(int i = 0; i < 6; i ++)
            if(i != lastnum)
                res = (res + dfs(n, 100000 + i * 10000 + index + 1, rollMax, dp)) % MOD;
            else if(lastfreq + 1 <= rollMax[i])
                res = (res + dfs(n, (lastfreq + 1) * 100000 + i * 10000 + index + 1, rollMax, dp)) % MOD;
        return dp[state] = res;
    }
};


int main() {

    vector<int> rollMax1 = {1, 1, 2, 2, 2, 3};
    cout << Solution().dieSimulator(2, rollMax1) << endl;
    // 34

    vector<int> rollMax2 = {1, 1, 1, 1, 1, 1};
    cout << Solution().dieSimulator(2, rollMax2) << endl;
    // 30

    vector<int> rollMax3 = {1, 1, 1, 2, 2, 3};
    cout << Solution().dieSimulator(3, rollMax3) << endl;
    // 181

    vector<int> rollMax4 = {13, 3, 12, 14, 11, 11};
    cout << Solution().dieSimulator(5000, rollMax4) << endl;
    // 538400505

    return 0;
}