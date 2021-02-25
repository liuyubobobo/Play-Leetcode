/// Source : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
/// Author : liuyubobobo
/// Time   : 2021-02-25

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {

private:
    int R, C;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        R = matrix.size();
        if(R == 0) return 0;

        C = matrix[0].size();
        if(C == 0) return 0;

        vector<vector<int>> dp(R, vector<int>(C, -1));
        int res = 1;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(dp[i][j] == -1) dfs(matrix, i, j, dp);
                res = max(res, dp[i][j]);
            }
        return res;
    }

private:
    int dfs(const vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp){

        if(dp[x][y] != -1) return dp[x][y];

        int res = 1;
        for(int d = 0; d < 4; d ++){
            int nextx = x + dirs[d][0], nexty = y + dirs[d][1];
            if(in_area(nextx, nexty) && matrix[nextx][nexty] > matrix[x][y])
                res = max(res, 1 + dfs(matrix, nextx, nexty, dp));
        }
        return dp[x][y] = res;
    }

    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    vector<vector<int>> matrix1 = {{9,9,4},{6,6,8},{2,1,1}};
    cout << Solution().longestIncreasingPath(matrix1) << endl;
    // 4

    vector<vector<int>> matrix2 = {{3,4,5},{3,2,6},{2,2,1}};
    cout << Solution().longestIncreasingPath(matrix2) << endl;
    // 4

    return 0;
}
