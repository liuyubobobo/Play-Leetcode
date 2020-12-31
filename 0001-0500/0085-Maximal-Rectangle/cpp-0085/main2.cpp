/// Source : https://leetcode.com/problems/maximal-rectangle/
/// Author : liuyubobobo
/// Time   : 2020-12-26

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming and Mono Stack
/// Time Complexity: O(R * C)
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

        int res = 0;
        for(int j = 0; j < C; j ++){
            vector<int> stack;
            stack.push_back(0);
            for(int i = 1; i < R; i ++){
                while(!stack.empty() && dp[i][j] < dp[stack.back()][j]){
                    int h = dp[stack.back()][j];
                    stack.pop_back();
                    int l = stack.empty() ? 0 : stack.back() + 1;
                    res = max(res, h * (i - l));
                }
                stack.push_back(i);
            }

            while(!stack.empty()){
                int h = dp[stack.back()][j];
                stack.pop_back();
                int l = stack.empty() ? 0 : stack.back() + 1;
                res = max(res, h * (R - l));
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
