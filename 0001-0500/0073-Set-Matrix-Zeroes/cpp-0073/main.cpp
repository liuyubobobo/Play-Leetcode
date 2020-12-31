/// Source : https://leetcode.com/problems/set-matrix-zeroes/description/
/// Author : liuyubobobo
/// Time   : 2018-10-05

#include <iostream>
#include <vector>

using namespace std;


/// Using another matrix to record zero place
/// Time Complexity: O(m * n * (m + n))
/// Space Complexity: O(m * n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        if(!m) return;

        int n = matrix[0].size();
        if(!n) return;

        vector<vector<bool>> isZero(m, vector<bool>(n, false));
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(!matrix[i][j]){
                    for(int k = 0; k < n; k ++)
                        isZero[i][k] = true;
                    for(int k = 0; k < m; k ++)
                        isZero[k][j] = true;
                }

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(isZero[i][j])
                    matrix[i][j] = 0;
    }
};


int main() {

    return 0;
}