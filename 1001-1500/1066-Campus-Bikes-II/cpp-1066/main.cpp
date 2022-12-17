/// Source : https://leetcode.com/problems/campus-bikes-ii/
/// Author : liuyubobobo
/// Time   : 2022-12-17

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// DP
/// Time Complexity: O(n * m * 2^m)
/// Space Complexity: O(n * 2^m)
class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {

        int n = workers.size(), m = bikes.size();
        vector<vector<int>> dis(n, vector<int>(m));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                dis[i][j] = get_dis(workers[i], bikes[j]);

        vector<vector<int>> dp(n, vector<int>(1 << m, -1));
        return dfs(n, m, dis, 0, 0, dp);
    }

private:
    int dfs(int n, int m, const vector<vector<int>>& dis, int index, int state,
            vector<vector<int>>& dp){

        if(index == n) return 0;
        if(dp[index][state] != -1) return dp[index][state];

        int res = INT_MAX;
        for(int j = 0; j < m; j ++){
            if(state & (1 << j)) continue;
            res = min(res, dis[index][j] + dfs(n, m, dis, index + 1, state | (1 << j), dp));
        }
        return dp[index][state] = res;
    }

    int get_dis(const vector<int>& v1, const vector<int>& v2){
        int x1 = v1[0], y1 = v1[1];
        int x2 = v2[0], y2 = v2[1];
        return abs(x1 - x2) + abs(y1 - y2);
    }
};


int main() {

    return 0;
}
