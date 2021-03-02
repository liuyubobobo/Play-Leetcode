/// Source : https://leetcode.com/problems/range-sum-query-2d-immutable/
/// Author : liuyubobobo
/// Time   : 2021-03-01

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: init:  O(n^2)
///                  query: O(1)
/// Space Complexity: O(n^2)
class NumMatrix {

private:
    vector<vector<int>> dp;

public:
    NumMatrix(vector<vector<int>>& matrix) {

        int R = matrix.size();
        if(R == 0) return;

        int C = matrix[0].size();
        if(C == 0) return;

        dp = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));

        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                dp[i + 1][j + 1] = matrix[i][j] + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};


int main() {

    return 0;
}
