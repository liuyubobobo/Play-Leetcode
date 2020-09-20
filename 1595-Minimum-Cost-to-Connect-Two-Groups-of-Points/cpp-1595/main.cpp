/// Source : https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/
/// Author : liuyubobobo
/// Time   : 2020-09-20

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Memory Search
/// Time Complexity: O(max(m, n) * (1 << m) * (1 << n))
/// Space Complexity: O((1 << m) * (1 << n))
class Solution {

private:
    int n, m;

public:
    int connectTwoGroups(vector<vector<int>>& cost) {

        n = cost.size(), m = cost[0].size();
        unordered_map<int, int> dp;
        return dfs(cost, 0, 0, 0, dp);
    }

private:
    int dfs(const vector<vector<int>>& c, int state1, int state2, int index,
            unordered_map<int, int>& dp){

        if(index == n + m)
            return 0;

        int hash = state1 * 10000 + state2;
        if(dp.count(hash)) return dp[hash];

        int res = INT_MAX;
        if(index < n){
            int p = index;
            if(state1 & (1 << p)) return dfs(c, state1, state2, index + 1, dp);
            for(int i = 0; i < m; i ++)
                res = min(res, c[p][i] + dfs(c, state1 | (1 << p), state2 | (1 << i), index + 1, dp));
        }
        else{
            int p = index - n;
            if(state2 & (1 << p)) return dfs(c, state1, state2, index + 1, dp);
            for(int i = 0; i < n; i ++)
                res = min(res, c[i][p] + dfs(c, state1 | (1 << i), state2 | (1 << p), index + 1, dp));
        }

        return dp[hash] = res;
    }
};


int main() {

    vector<vector<int>> cost1 = {
            {15, 96}, {36, 2}
    };
    cout << Solution().connectTwoGroups(cost1) << endl;
    // 17

    vector<vector<int>> cost2 = {
            {1, 3, 5}, {4, 1, 1}, {1, 5, 3}
    };
    cout << Solution().connectTwoGroups(cost2) << endl;
    // 4

    vector<vector<int>> cost3 = {
            {2, 5, 1}, {3, 4, 7}, {8, 1, 2}, {6, 2, 4}, {3, 8, 8}
    };
    cout << Solution().connectTwoGroups(cost3) << endl;
    // 10

    return 0;
}