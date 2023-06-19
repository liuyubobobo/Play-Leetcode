/// Source : https://leetcode.com/problems/painting-the-walls/description/
/// Author : liuyubobobo
/// Time   : 2023-06-18

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memoization
/// Time Complexity: O(n * (total_time + n))
/// Space Complexity: O(n * (total_time + n))
class Solution {

private:
    const int INF = INT_MAX / 2;

public:
    int paintWalls(vector<int>& cost, vector<int>& time) {

        int n = cost.size();
        int total_time = accumulate(time.begin(), time.end(), 0);

        vector<vector<int>> dp(n, vector<int>(total_time + n + 1, -1));
        return dfs(n, cost, time, 0, 0, n, dp);
    }

private:
    int dfs(int n, const vector<int>& cost, const vector<int>& time,
            int index, int can_be_free_time, int offset, vector<vector<int>>& dp) {

        if(index == n) return can_be_free_time >= 0 ? 0 : INF;
        if(dp[index][can_be_free_time + offset] != -1) return dp[index][can_be_free_time + offset];

        int res = INF;
        res = min(res, cost[index] + dfs(n, cost, time, index + 1, can_be_free_time + time[index], offset, dp));
        res = min(res, dfs(n, cost, time, index + 1, can_be_free_time - 1, offset, dp));
        return dp[index][can_be_free_time + offset] = res;
    }
};


int main() {

    return 0;
}
