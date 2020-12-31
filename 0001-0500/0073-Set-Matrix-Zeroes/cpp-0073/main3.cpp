/// Source : https://leetcode.com/problems/set-matrix-zeroes/description/
/// Author : liuyubobobo
/// Time   : 2018-10-05

#include <iostream>
#include <vector>

using namespace std;


/// Using an sentinel value to mark zero in place
/// Attention: this method is actually wrong since we can not guarantee that
///            the sentinel value can not occur in the matrix
///
/// Time Complexity: O(m * n * (m + n))
/// Space Complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        if(!m) return;

        int n = matrix[0].size();
        if(!n) return;

        int sentinel = 2e9;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(matrix[i][j] == 0){
                    for(int k = 0; k < n; k ++)
                        if(matrix[i][k] != 0)
                            matrix[i][k] = sentinel;
                    for(int k = 0; k < m; k ++)
                        if(matrix[k][j] != 0)
                            matrix[k][j] = sentinel;
                }

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(matrix[i][j] == sentinel)
                    matrix[i][j] = 0;
    }
};


int main() {

    return 0;
}