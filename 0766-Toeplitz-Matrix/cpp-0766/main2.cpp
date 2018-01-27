/// Source : https://leetcode.com/problems/toeplitz-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-01-26
#include <iostream>
#include <vector>

using namespace std;


/// Iterate all diagonal elements
/// Time Complexity: O(N^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        for(int i = 0; i < matrix.size() ; i ++)
            if(!ok(matrix, i, 0))
                return false;

        for(int j = 1 ; j < matrix[0].size() ; j ++)
            if(!ok(matrix, 0, j))
                return false;

        return true;
    }

private:
    bool ok(const vector<vector<int>>& matrix, int i, int j){
        int target = matrix[i][j];
        while(i < matrix.size() && j < matrix[i].size()){
            if(matrix[i][j] != target)
                return false;
            i ++;
            j ++;
        }
        return true;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {
    vector<vector<int>> matrix1 = {{1,2,3,4}, {5,1,2,3}, {9,5,1,2}};
    printBool(Solution().isToeplitzMatrix(matrix1));

    vector<vector<int>> matrix2 = {{1, 2}, {2, 2}};
    printBool(Solution().isToeplitzMatrix(matrix2));

    return 0;
}