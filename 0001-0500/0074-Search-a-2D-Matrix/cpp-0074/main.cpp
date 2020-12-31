/// Source : https://leetcode.com/problems/search-a-2d-matrix/
/// Author : liuyubobobo
/// Time   : 2019-05-02

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Two steps Binary Search
/// Time Complexity: O(logn + logm)
/// Space Complexity: O(m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(!matrix.size() || !matrix[0].size()) return false;
        if(target < matrix[0][0]) return false;

        vector<int> row;
        for(int i = 0; i < matrix.size(); i ++)
            row.push_back(matrix[i][0]);

        int row_index = lower_bound(row.begin(), row.end(), target) - row.begin();
        if(row_index == matrix.size() || matrix[row_index][0] != target)
            row_index --;
//        cout << row_index << endl;

        vector<int>::iterator iter = lower_bound(matrix[row_index].begin(), matrix[row_index].end(), target);
        return iter != matrix[row_index].end() && *iter == target;
    }
};


int main() {

    vector<vector<int>> matrix1 = {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 50}
    };
    cout << Solution().searchMatrix(matrix1, 3) << endl;
    // true

    vector<vector<int>> matrix2 = {
            {1}
    };
    cout << Solution().searchMatrix(matrix2, 2) << endl;
    // false

    return 0;
}