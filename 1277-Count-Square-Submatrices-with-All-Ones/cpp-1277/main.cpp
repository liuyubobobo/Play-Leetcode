/// Source : https://leetcode.com/problems/count-square-submatrices-with-all-ones/
/// Author : liuyubobobo
/// Time   : 2020-05-21

#include <iostream>
#include <vector>

using namespace std;


/// Presum in 2D
/// Time Compelxity: O(m * n * min(m, n))
/// Space Complexity: O(m * n)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> presum(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                presum[i + 1][j + 1] = presum[i][j + 1] + presum[i + 1][j] - presum[i][j] + matrix[i][j];

        int res = 0;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                for(int len = 1; len <= min(i + 1, j + 1); len ++){
                    if(presum[i + 1][j + 1] - presum[i + 1 - len][j + 1] - presum[i + 1][j + 1 - len] + presum[i + 1 - len][j + 1 - len] == len * len)
                        res ++;
                    else
                        break;
                }
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
