/// Source : https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
/// Author : liuyubobobo
/// Time   : 2022-07-11

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(m * n * (m + n))
/// Space Complexity: O(m * n)
class Solution {
public:
    int oddCells(int R, int C, vector<vector<int>>& indices) {

        vector<vector<int>> matrix(R, vector<int>(C, 0));
        for(const vector<int>& e: indices){
            int r = e[0], c = e[1];
            for(int j = 0; j < C; j ++) matrix[r][j] ++;
            for(int i = 0; i < R; i ++) matrix[i][c] ++;
        }

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++) res += matrix[i][j] % 2;
        return res;
    }
};


int main() {

    return 0;
}
