/// Source : https://leetcode.com/problems/01-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-09-30

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m*n)
/// Space Complexity: O(1)
class Solution {

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        if(matrix.size() == 0 || matrix[0].size() == 0)
            return matrix;

        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> res(m, vector<int>(n, m + n + 1));
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(matrix[i][j] == 0)
                    res[i][j] = 0;

        // top
        for(int i = 1; i < m; i ++)
            for(int j = 0; j < n; j ++)
                res[i][j] = min(1 + res[i - 1][j], res[i][j]);

        // left
        for(int i = 0; i < m; i ++)
            for(int j = 1; j < n; j ++)
                res[i][j] = min(1 + res[i][j - 1], res[i][j]);

        // bottom
        for(int i = m - 2; i >= 0; i --)
            for(int j = n - 1; j >= 0; j --)
                res[i][j] = min(1 + res[i + 1][j], res[i][j]);

        // right
        for(int i = m - 1; i >= 0; i --)
            for(int j = n - 2; j >= 0; j --)
                res[i][j] = min(1 + res[i][j + 1], res[i][j]);

        return res;
    }
};


int main() {

    return 0;
}