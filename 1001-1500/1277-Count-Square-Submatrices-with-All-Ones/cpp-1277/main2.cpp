/// Source : https://leetcode.com/problems/count-square-submatrices-with-all-ones/
/// Author : liuyubobobo
/// Time   : 2020-05-21

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Compelxity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int res = 0;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(matrix[i][j])
                    dp[i + 1][j + 1] = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i][j]) + 1,
                    res += dp[i + 1][j + 1];
        return res;
    }
};


int main() {

    vector<vector<int>> matrix1 = {
            {0,1,1,1},
            {1,1,1,1},
            {0,1,1,1}
    };
    cout << Solution().countSquares(matrix1) << endl;
    // 15

    return 0;
}
