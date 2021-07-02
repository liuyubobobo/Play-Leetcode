/// Source : https://leetcode.com/problems/rotate-image/description/
/// Author : liuyubobobo
/// Time   : 2018-09-13

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        for(int i = 0; i <= n / 2; i ++)
            for(int j = i; j < n - 1 - i; j ++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = t;
                Solution::print_matrix(matrix);
            }
    }

    static void print_matrix(const vector<vector<int>>& m){
        for(int i = 0; i < m.size(); i ++){
            for(int j = 0; j < m[i].size(); j ++)
                cout << m[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};


int main() {

    vector<vector<int>> matrix1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    Solution().rotate(matrix1);
    Solution::print_matrix(matrix1);

    vector<vector<int>> matrix2 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
    };
    Solution().rotate(matrix2);
    Solution::print_matrix(matrix2);

    return 0;
}