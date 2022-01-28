/// Source : https://leetcode.com/problems/minimum-number-of-lines-to-cover-points/
/// Author : liuyubobobo
/// Time   : 2022-01-27

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memoization
/// Time Complexity: O(2^n * n^2)
/// Space Complexity: O(2^n)
class Solution {

public:
    int minimumLines(vector<vector<int>>& points) {

        int n = points.size();
        vector<int> dp(1 << n, -1);
        return dfs(n, points, 0, dp);
    }

private:
    int dfs(int n, const vector<vector<int>>& points, int state, vector<int>& dp){

        int used_total = __builtin_popcount(state);
        if(n - used_total == 0) return 0;
        if(n - used_total <= 2) return 1;
        if(dp[state] != -1) return dp[state];

        int res = INT_MAX;
        for(int i = 0; i < n; i ++){
            if(state & (1 << i)) continue;
            for(int j = i + 1; j < n; j ++){
                if(state & (1 << j)) continue;

                vector<int> in_line_index = {i, j};
                for(int k = j + 1; k < n; k ++){
                    if(state & (1 << k)) continue;
                    if(in_line(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]))
                        in_line_index.push_back(k);
                }

                for(int index: in_line_index) state |= (1 << index);
                res = min(res, 1 + dfs(n, points, state, dp));
                for(int index: in_line_index) state -= (1 << index);
            }
        }
        return dp[state] = res;
    }

    bool in_line(int x1, int y1, int x2, int y2, int x, int y){
        return (y - y1) * (x - x2) == (y - y2) * (x - x1);
    }
};


int main() {

    vector<vector<int>> points1 = {
            {4,-8},{-7,5},{9,7},{-10,10},{6,8},
            {-3,-6},{-1,3},{-10,9},{1,-3},{8,3}
    };
    cout << Solution().minimumLines(points1) << endl;
    // 5

    return 0;
}
