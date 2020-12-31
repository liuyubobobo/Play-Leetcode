/// Source : https://leetcode.com/contest/weekly-contest-163/problems/shift-2d-grid/
/// Author : liuyubobobo
/// Time   : 2019-11-16

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(k * m * n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res = grid;
        while(k --)
            res = go(res, n, m);
        return res;
    }

private:
    vector<vector<int>> go(const vector<vector<int>>& g, int n, int m){

        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i ++){
            res[i][0] = g[(i - 1 + n) % n][m - 1];
            for(int j = 1; j < m; j ++)
                res[i][j] = g[i][j - 1];
        }
        return res;
    }
};


int main() {

    return 0;
}