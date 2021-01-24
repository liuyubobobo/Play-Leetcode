/// Source : https://leetcode.com/problems/sort-the-matrix-diagonally/
/// Author : liuyubobobo
/// Time   : 2021-01-24

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(R * C * log(max(R, C)))
/// Space Complexity: O(1)
class Solution {

private:
    int R, C;

public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        R = mat.size(), C = mat[0].size();
        for(int j = 0; j < C; j ++) deal(mat, 0, j);
        for(int i = 1; i < R; i ++) deal(mat, i, 0);
        return mat;
    }

private:
    void deal(vector<vector<int>>& mat, int x, int y){

        vector<int> v;
        for(int d = 0; x + d < R && y + d < C; d ++)
            v.push_back(mat[x + d][y + d]);

        sort(v.begin(), v.end());

        for(int d = 0; x + d < R && y + d < C; d ++)
           mat[x + d][y + d] = v[d];
    }
};


int main() {

    return 0;
}
