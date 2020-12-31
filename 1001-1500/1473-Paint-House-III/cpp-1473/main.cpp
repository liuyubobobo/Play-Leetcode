/// Source : https://leetcode.com/problems/paint-house-iii/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(m^2 * n^2)
/// Space Complexity: O(m^2 * n)
class Solution {

private:
    int n;
    const int INF = 1e7;

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {

        this->n = n;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(m + 1, -1)));
        int res = dfs(houses, 0, 0, target, cost, dp);
        return res == INF ? -1 : res;
    }

private:
    int dfs(const vector<int>& houses, int index, int precolor, int target,
            const vector<vector<int>>& cost, vector<vector<vector<int>>>& dp){

        if(target < 0) return INF;
        if(index == houses.size()) return target ? INF : 0;
        if(dp[index][precolor][target] != -1) return dp[index][precolor][target];

        int res = INF;
        if(!houses[index]){
            for(int i = 1; i <= n; i ++)
                res = min(res, cost[index][i - 1] + dfs(houses, index + 1, i, i == precolor ? target : target - 1, cost, dp));
        }
        else
            res = dfs(houses, index + 1, houses[index], houses[index] == precolor ? target : target - 1, cost, dp);

        return dp[index][precolor][target] = res;
    }
};


int main() {

    return 0;
}
