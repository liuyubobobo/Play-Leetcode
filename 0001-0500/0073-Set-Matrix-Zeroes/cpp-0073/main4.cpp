/// Source : https://leetcode.com/problems/set-matrix-zeroes/description/
/// Author : liuyubobobo
/// Time   : 2018-10-05

#include <iostream>
#include <vector>

using namespace std;


/// Make a marker in the first element of every row and column
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        if(!m) return;

        int n = matrix[0].size();
        if(!n) return;

        bool zeroIndexColZero = false;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    if(j == 0)
                        zeroIndexColZero = true;
                    else
                        matrix[0][j] = 0;
                }

        for(int i = 1; i < m; i ++)
            if(!matrix[i][0])
                for(int j = 0; j < n; j ++)
                    matrix[i][j] = 0;

        for(int j = 1; j < n; j ++)
            if(!matrix[0][j])
                for(int i = 0; i < m; i ++)
                    matrix[i][j] = 0;

        if(!matrix[0][0])
            for(int j = 0; j < n; j ++)
                matrix[0][j] = 0;

        if(zeroIndexColZero)
            for(int i = 0; i < m; i ++)
                matrix[i][0] = 0;
    }
};


void print_matrix(const vector<vector<int>>& matrix){

    for(const vector<int>& row: matrix){
        for(int e: row)
            cout << e << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {

    vector<vector<int>> matrix1 = {
            {1,1,1},{1,0,1},{1,1,1}
    };
    Solution().setZeroes(matrix1);
    print_matrix(matrix1);

    vector<vector<int>> matrix2 = {
            {0,1,2,0},{3,4,5,2},{1,3,1,5}
    };
    Solution().setZeroes(matrix2);
    print_matrix(matrix2);

    return 0;
}