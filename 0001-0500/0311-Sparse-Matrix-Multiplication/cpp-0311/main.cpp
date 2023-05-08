/// Source : https://leetcode.com/problems/sparse-matrix-multiplication/description/
/// Author : liuyubobobo
/// Time   : 2023-05-07

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * m * k)
/// Space Complexity: O(n * m)
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {

        int n = mat1.size(), k = mat1[0].size(), m = mat2[0].size();

        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                for(int p = 0; p < k; p ++)
                    res[i][j] += mat1[i][p] * mat2[p][j];
        return res;
    }
};


int main() {

    return 0;
}
