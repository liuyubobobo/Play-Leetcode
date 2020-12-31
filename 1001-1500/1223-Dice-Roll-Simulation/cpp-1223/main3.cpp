/// Source : https://leetcode.com/problems/dice-roll-simulation/
/// Author : liuyubobobo
/// Time   : 2019-10-12

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n * 6 * max(rollMax) * 6)
/// Space Complexity: O(n * 6 * max(rollMax))
class Solution {

public:
    int dieSimulator(int n, vector<int>& rollMax) {

        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(*max_element(rollMax.begin(), rollMax.end()) + 1, vector<int>(6, 0)));
        for(int i = 0; i < 6; i ++)
            dp[0][1][i] = 1;

        for(int index = 1; index < n; index ++)
            for(int lastnum = 0; lastnum < 6; lastnum ++)
                for(int lastfreq = 0; lastfreq <= rollMax[lastnum]; lastfreq ++)
                    for(int i = 0; i < 6; i ++)
                        if(i != lastnum)
                            dp[index][1][i] += dp[index - 1][lastfreq][lastnum],
                            dp[index][1][i] %= MOD;
                        else if(lastfreq + 1 <= rollMax[lastnum])
                            dp[index][lastfreq + 1][i] += dp[index - 1][lastfreq][lastnum],
                            dp[index][lastfreq + 1][i] %= MOD;

        int res = 0;
        for(int i = 0; i < dp[n - 1].size(); i ++)
            for(int e: dp[n - 1][i])
                res = (res + e) % MOD;
        return res;
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