/// Source : https://leetcode.com/problems/rotate-image/description/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <vector>

using namespace std;


/// Reverse diagonally and then reverse row
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n - i; j ++)
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);

        for(int i = 0; i < n / 2; i ++)
            for(int j = 0; j < n; j ++)
                swap(matrix[i][j], matrix[n - i - 1][j]);
    }
};


void print_matrix(const vector<vector<int>>& m){
    for(int i = 0; i < m.size(); i ++){
        for(int j = 0; j < m[i].size(); j ++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {

    vector<vector<int>> matrix1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution().rotate(matrix1);
    print_matrix(matrix1);

    vector<vector<int>> matrix2 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    };
    Solution().rotate(matrix2);
    print_matrix(matrix2);

    return 0;
}