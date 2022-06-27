/// Source : https://leetcode.com/problems/check-if-matrix-is-x-matrix/
/// Author : liuyubobobo
/// Time   : 2022-06-25

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++){
                if(is_dia(i, j, n) && grid[i][j] == 0) return false;
                if(!is_dia(i, j, n) && grid[i][j] != 0) return false;
            }
        return true;
    }

private:
    bool is_dia(int i, int j, int n){
        return i == j || i + j == n - 1;
    }
};


int main() {

    return 0;
}
