/// Source : https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/
/// Author : liuyubobobo
/// Time   : 2022-12-02

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(R * C)
/// Space Complexity: O(R + C)
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> res(R, vector<int>(C));

        vector<int> onesRow(R, 0), zerosRow(R, 0);
        vector<int> onesCol(C, 0), zerosCol(C, 0);
        for(int i = 0; i < R; i ++){
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == 0) zerosRow[i] ++, zerosCol[j] ++;
                else onesRow[i] ++, onesCol[j] ++;
        }

        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                res[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
        return res;
    }
};


int main() {

    return 0;
}
