/// Source : https://leetcode.com/problems/set-matrix-zeroes/description/
/// Author : liuyubobobo
/// Time   : 2018-10-05

#include <iostream>
#include <vector>

using namespace std;


/// Only record the zero row index and col index
/// Time Complexity: O(m * n)
/// Space Complexity: O(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        if(!m) return;

        int n = matrix[0].size();
        if(!n) return;

        vector<int> zeroRows, zeroCols;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(!matrix[i][j]){
                    zeroRows.push_back(i);
                    zeroCols.push_back(j);
                }

        for(int r: zeroRows)
            for(int j = 0; j < n; j ++)
                matrix[r][j] = 0;

        for(int c: zeroCols)
            for(int i = 0; i < m; i ++)
                matrix[i][c] = 0;
    }
};


int main() {

    return 0;
}