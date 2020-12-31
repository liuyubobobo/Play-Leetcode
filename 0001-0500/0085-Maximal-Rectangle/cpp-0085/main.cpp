/// Source : https://leetcode.com/problems/maximal-rectangle/
/// Author : liuyubobobo
/// Time   : 2020-12-26

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(R * C * R)
/// Space Complexity: O(R * C)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        if(!matrix.size() || !matrix[0].size()) return 0;

        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> dp(R, vector<int>(C, 0));
        for(int i = 0; i < matrix.size(); i ++){
            dp[i][0] = matrix[i][0] - '0';
            for(int j = 1; j < C; j ++)
                if(matrix[i][j] == '1')
                    dp[i][j] = dp[i][j - 1] + 1;
        }

        int res = *max_element(dp[0].begin(), dp[0].end());

        for(int i = 1; i < R; i ++)
            for(int j = 0; j < C; j ++){
                int w = dp[i][j];
                for(int k = i; k >= 0 && w; k --){
                    w = min(w, dp[k][j]);
                    res = max(res, w * (i - k + 1));
                }
            }
        return res;
    }
};


int main() {

    return 0;
}
