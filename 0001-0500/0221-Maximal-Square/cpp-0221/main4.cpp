/// Source : https://leetcode.com/problems/maximal-square/
/// Author : liuyubobobo
/// Time   : 2020-01-06

#include <iostream>
#include <vector>

using namespace  std;


/// Dynamic Programming with Space Optimization
/// Time Complexity: O(m * n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.size() == 0) return 0;

        vector<int> dp(matrix[0].size() + 1, 0);
        int res = 0, pre = 0;
        for(int i = 0; i < matrix.size(); i ++)
            for(int j = 0; j < matrix[i].size(); j ++){
                int temp = dp[j + 1];
                if(matrix[i][j] == '1'){
                    dp[j + 1] = min(dp[j], min(dp[j + 1], pre)) + 1;
                    res = max(res, dp[j + 1]);
                }
                else dp[j + 1] = 0;
                pre = temp;
            }
        return res * res;
    }
};


int main() {

    return 0;
}
