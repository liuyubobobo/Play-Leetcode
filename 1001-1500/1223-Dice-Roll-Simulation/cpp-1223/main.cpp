/// Source : https://leetcode.com/problems/dice-roll-simulation/
/// Author : liuyubobobo
/// Time   : 2019-10-12

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n * 6 * max(rollMax) * 6)
/// Space Complexity: O(n * 6 * max(rollMax))
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int dieSimulator(int n, vector<int>& rollMax) {

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(*max_element(rollMax.begin(), rollMax.end()) + 1, vector<int>(6, -1)));
        int res = 0;
        for(int i = 0; i < 6; i ++)
            res = (res + dfs(n, 1, 1, i, rollMax, dp))% MOD;
        return res;
    }

private:
    int dfs(int n, int index, int lastfreq, int lastnum,
            const vector<int>& rollMax, vector<vector<vector<int>>>& dp){

        if(index == n) return 1;
        if(dp[index][lastfreq][lastnum] != -1) return dp[index][lastfreq][lastnum];

        int res = 0;
        for(int i = 0; i < 6; i ++)
            if(i != lastnum)
                res = (res + dfs(n, index + 1, 1, i, rollMax, dp)) % MOD;
            else if(lastfreq + 1 <= rollMax[i])
                res = (res + dfs(n, index + 1, lastfreq + 1, i, rollMax, dp)) % MOD;
        return dp[index][lastfreq][lastnum] = res;
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