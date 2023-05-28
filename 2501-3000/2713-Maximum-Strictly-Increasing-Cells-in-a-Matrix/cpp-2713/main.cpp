#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {

        int R = mat.size(), C = mat[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++) pq.push({mat[i][j], i * C + j});

        vector<int> row(R, 0), col(C, 0);
        vector<int> rowv(R, INT_MIN), colv(C, INT_MIN);
        vector<vector<int>> dp(R, vector<int>(C, 0));
        int res = 0;
        while(!pq.empty()){
            int v = pq.top().first, pos = pq.top().second;
            pq.pop();
            int r = pos / C, c = pos % C;

            if(v > rowv[r]) dp[r][c] = max(dp[r][c], row[r] + 1);
            else dp[r][c] = max(dp[r][c], row[r]);
            if(v > colv[c]) dp[r][c] = max(dp[r][c], col[c] + 1);
            else dp[r][c] = max(dp[r][c], col[c]);

            if(dp[r][c] > row[r]) row[r] = dp[r][c], rowv[r] = v;
            if(dp[r][c] > col[c]) col[c] = dp[r][c], colv[c] = v;

            res = max(res, dp[r][c]);
        }
        return res;
    }
};


int main() {

//    vector<vector<int>> mat1 = {{3, 1}, {3, 4}};
//    cout << Solution().maxIncreasingCells(mat1) << '\n';
//    // 2
//
//    vector<vector<int>> mat2 = {{1, 1}, {1, 1}};
//    cout << Solution().maxIncreasingCells(mat2) << '\n';
//    // 1
//
//    vector<vector<int>> mat3 = {{3, 1, 6}, {-9, 5, 7}};
//    cout << Solution().maxIncreasingCells(mat3) << '\n';
//    // 4
//
//    vector<vector<int>> mat4 = {{7, 6, 3}, {-7, -5, 6}, {-7, 0, -4}, {6, 6, 0}, {-8, 6, 0}};
//    cout << Solution().maxIncreasingCells(mat4) << '\n';
//    // 7

    vector<vector<int>> mat5 = {{3, 1}, {3, 4}};
    cout << Solution().maxIncreasingCells(mat5) << '\n';
    // 2

    return 0;
}
