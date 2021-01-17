/// Source : https://leetcode.com/problems/largest-submatrix-with-rearrangements/
/// Author : liuyubobobo
/// Time   : 2021-01-17

#include <iostream>
#include <vector>

using namespace std;


/// DP and Sorting
/// Time Complexity: O(R * ClogC)
/// Space Complexity: O(C)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        int R = matrix.size(), C = matrix[0].size();

        int res = 0;
        for(int i = 0; i < R; i ++){

            vector<int> cur = matrix[i];
            sort(cur.begin(), cur.end());

            for(int j = C - 1; j >= 0; j --)
                res = max(res, cur[j] * (C - j));

            if(i + 1 < R){
                for(int j = 0; j < C; j ++)
                    matrix[i + 1][j] = matrix[i + 1][j] == 0 ? 0 : (matrix[i][j] + 1);
            }
        }
        return res;
    }
};


int main() {

    vector<vector<int>> matrix1 = {
            {0, 0, 1}, {1, 1, 1}, {1, 0, 1}
    };
    cout << Solution().largestSubmatrix(matrix1) << endl;
    // 4

    vector<vector<int>> matrix2 = {
            {1, 0, 1, 0, 1}
    };
    cout << Solution().largestSubmatrix(matrix2) << endl;
    // 3

    vector<vector<int>> matrix3 = {
            {1, 1, 0},{1, 0, 1}
    };
    cout << Solution().largestSubmatrix(matrix3) << endl;
    // 2

    vector<vector<int>> matrix4 = {
            {0, 0},{0, 0}
    };
    cout << Solution().largestSubmatrix(matrix4) << endl;
    // 0

    return 0;
}
