/// Source : https://leetcode.com/problems/search-a-2d-matrix/
/// Author : liuyubobobo
/// Time   : 2019-05-02

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Think the whole 2d matrix as a 1d array and Binary Search
///
/// Time Complexity: O(log(m*n))
/// Space Complexity: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(!matrix.size() || !matrix[0].size()) return false;

        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int x = matrix[mid / n][mid % n];
            if(target == x) return true;
            else if(target < x) r = mid - 1;
            else l = mid + 1;
        }
        return false;
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