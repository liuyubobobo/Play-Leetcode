/// Source : https://leetcode-cn.com/problems/ZbAuEH/
/// Author : liuyubobobo
/// Time   : 2022-04-23

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Memoization
/// Time Compelxity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const vector<vector<vector<int>>> next ={
            {{0}, {1, 3}, {2, 4, 6}, {5, 7}, {8}},
            {{1}, {0, 2, 4}, {3, 5, 7}, {6, 8}},
            {{2}, {1, 5}, {0, 4, 8}, {3, 7}, {6}},
            {{3}, {0, 4, 6}, {1, 5, 7}, {2, 8}},
            {{4}, {1, 3, 5, 7}, {0, 2, 6, 8}},
            {{5}, {2, 4, 8}, {1, 3, 7}, {0, 6}},
            {{6}, {3, 7}, {0, 4, 8}, {1, 5}, {2}},
            {{7}, {4, 6, 8}, {1, 3, 5}, {0, 2}},
            {{8}, {5, 7}, {2, 4, 6}, {1, 3}, {0}}
    };

public:
    int getMaximumNumber(vector<vector<int>>& moles) {

        int n = moles.size();
        vector<pair<int, int>> data(n); // t, pos
        for(int i = 0; i < n; i ++)
            data[i] = {moles[i][0], moles[i][1] * 3 + moles[i][2]};
        sort(data.begin(), data.end());

        vector<vector<int>> dp(9, vector<int>(n, -1));
        int res = 0;
        for(int t = 0; t <= data[0].first && t < next[4].size(); t ++)
            for(int pos: next[4][t])
                res = max(res, dfs(n, data, pos, 0, dp));
        return res;
    }

private:
    int dfs(int n, const vector<pair<int, int>>& data, int pos, int index,
            vector<vector<int>>& dp){

        if(index == n - 1)
            return pos == data[index].second;
        if(dp[pos][index] != -1) return dp[pos][index];

        int T = data[index + 1].first - data[index].first;
        int res = 0;
        for(int t = 0; t <= T && t < next[pos].size(); t ++)
            for(int next_pos: next[pos][t])
                res = max(res, (data[index].second == pos) + dfs(n, data, next_pos, index + 1, dp));
        return dp[pos][index] = res;
    }
};


int main() {

    return 0;
}
