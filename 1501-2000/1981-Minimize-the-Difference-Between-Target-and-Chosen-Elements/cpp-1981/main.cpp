/// Source : https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
/// Author : liuyubobobo
/// Time   : 2021-08-21

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(R * C * target)
/// Space Complexity: O(R * target)
class Solution {

private:
    int R, C;

public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

        for(vector<int>& row: mat) sort(row.begin(), row.end());

        R = mat.size(), C = mat[0].size();
        vector<vector<int>> dp(R, vector<int>(target + 1, -1));
        return dfs(mat, 0, target, dp);
    }

private:
    int dfs(const vector<vector<int>>& mat, int r, int t,
            vector<vector<int>>& dp){

        if(r == R) return t;
        if(dp[r][t] != -1) return dp[r][t];

        int res = INT_MAX;
        for(int j = 0; j < C; j ++){
            if(t >= mat[r][j])
                res = min(res, dfs(mat, r + 1, t - mat[r][j], dp));
            else{
                int tres = t - mat[r][j];
                for(int i =  r + 1; i < R; i ++)
                    tres -= mat[i][0];
                res = min(res, -tres);
            }
        }
        return dp[r][t] = res;
    }
};


int main() {

    vector<vector<int>> mat1 = {
            {1,2,3},{4,5,6},{7,8,9}
    };
    cout << Solution().minimizeTheDifference(mat1, 13) << endl;
    // 0

    vector<vector<int>> mat2 = {
            {1},{2},{3}
    };
    cout << Solution().minimizeTheDifference(mat2, 100) << endl;
    // 94

    vector<vector<int>> mat3 = {
            {1,2,9,8,7}
    };
    cout << Solution().minimizeTheDifference(mat3, 6) << endl;
    // 1

    return 0;
}
