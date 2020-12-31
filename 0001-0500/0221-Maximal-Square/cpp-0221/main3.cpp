/// Source : https://leetcode.com/problems/maximal-square/
/// Author : liuyubobobo
/// Time   : 2020-01-06

#include <iostream>
#include <vector>

using namespace  std;


/// Dynamic Programming
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.size() == 0) return 0;

        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int res = 0;
        for(int i = 0; i < matrix.size(); i ++)
            for(int j = 0; j < matrix[i].size(); j ++)
                if(matrix[i][j] == '1'){
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
                    res = max(res, dp[i + 1][j + 1]);
                }
        return res * res;
    }
};


int main() {

    return 0;
}
