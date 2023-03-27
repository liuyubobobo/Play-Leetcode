/// Source : https://leetcode.com/problems/check-knight-tour-configuration/description/
/// Author : liuyubobobo
/// Time   : 2023-03-25

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> x(n * n, -1), y(n * n, -1);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++) x[grid[i][j]] = i, y[grid[i][j]] = j;

        if(x.back() == -1) return false;
        if(x[0] || y[0]) return false;

        for(int i = 1; i < n * n; i ++)
            if(!check(x[i - 1], y[i - 1], x[i], y[i])) return false;
        return true;
    }

private:
    bool check(int x1, int y1, int x2, int y2){
        int dx = abs(x1 - x2), dy = abs(y1 - y2);
        return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
    }
};


int main() {


    return 0;
}
