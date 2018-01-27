/// Source : https://leetcode.com/problems/toeplitz-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-01-26
#include <iostream>
#include <vector>

using namespace std;


/// Compare with all diagonal neighbors
/// Time Complexity: O(N^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        for(int i = 0 ; i < matrix.size() ; i ++)
            for(int j = 0 ; j < matrix[i].size() ; j ++)
                if(i - 1 >= 0 && j - 1 >= 0)
                    if(matrix[i][j] != matrix[i-1][j-1])
                        return false;

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