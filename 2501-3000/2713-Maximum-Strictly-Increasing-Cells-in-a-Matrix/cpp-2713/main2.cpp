/// Source : https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/description/
/// Author : liuyubobobo
/// Time   : 2023-05-27

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


/// DAG DP
/// Time Complexity: O(R * C * log(R * C))
/// Space Complexity: O(R + C)
class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {

        int R = mat.size(), C = mat[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++) pq.push({mat[i][j], i * C + j});

        vector<int> row1(R, 0), col1(C, 0), row2(R, 0), col2(C, 0);
        vector<int> rowv1(R, INT_MIN), colv1(C, INT_MIN), rowv2(R, INT_MIN), colv2(C, INT_MIN);
        vector<vector<int>> dp(R, vector<int>(C, 0));
        int res = 0;
        while(!pq.empty()){
            int v = pq.top().first, pos = pq.top().second;
            pq.pop();
            int r = pos / C, c = pos % C;

            if(v > rowv1[r]) dp[r][c] = max(dp[r][c], row1[r] + 1);
            else dp[r][c] = max(dp[r][c], row2[r] + 1);

            if(v > colv1[c]) dp[r][c] = max(dp[r][c], col1[c] + 1);
            else dp[r][c] = max(dp[r][c], col2[c] + 1);

            if(v > rowv1[r] && dp[r][c] > row1[r]){
                row2[r] = row1[r], rowv2[r] = rowv1[r];
                row1[r] = dp[r][c], rowv1[r] = v;
            }
            else if(v == rowv1[r] && dp[r][c] > row1[r]) row1[r] = dp[r][c];

            if(v > colv1[c] && dp[r][c] > col1[c]){
                col2[c] = col1[c], colv2[c] = colv1[c];
                col1[c] = dp[r][c], colv1[c] = v;
            }
            else if(v == colv1[c] && dp[r][c] > col1[c]) col1[c] = dp[r][c];

            res = max(res, dp[r][c]);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> mat1 = {{3, 1}, {3, 4}};
    cout << Solution().maxIncreasingCells(mat1) << '\n';
    // 2

    vector<vector<int>> mat2 = {{1, 1}, {1, 1}};
    cout << Solution().maxIncreasingCells(mat2) << '\n';
    // 1

    vector<vector<int>> mat3 = {{3, 1, 6}, {-9, 5, 7}};
    cout << Solution().maxIncreasingCells(mat3) << '\n';
    // 4

    vector<vector<int>> mat4 = {{7, 6, 3}, {-7, -5, 6}, {-7, 0, -4}, {6, 6, 0}, {-8, 6, 0}};
    cout << Solution().maxIncreasingCells(mat4) << '\n';
    // 7

    vector<vector<int>> mat5 = {{3, 1}, {3, 4}};
    cout << Solution().maxIncreasingCells(mat5) << '\n';
    // 2

    return 0;
}
