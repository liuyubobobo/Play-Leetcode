/// Source : https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/
/// Author : liuyubobobo
/// Time   : 2023-05-27

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


/// Simulation
/// Time Complexity: O(R * C * max(R, C))
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        vector<vector<int>> res(R, vector<int>(C));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                res[i][j] = solve(R, C, grid, i, j);
        return res;
    }

private:
    int solve(int R, int C, vector<vector<int>>& grid, int x, int y){

        int cx = x, cy = y;
        set<int> s1;
        while(-- cx >= 0 && -- cy >= 0)
            s1.insert(grid[cx][cy]);

        cx = x, cy = y;
        set<int> s2;
        while(++ cx < R && ++ cy < C)
            s2.insert(grid[cx][cy]);

        int t = (int)s1.size() - (int)s2.size();
        return abs(t);
    }
};


int main() {

    return 0;
}
