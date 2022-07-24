/// Source : https://leetcode.com/problems/equal-row-and-column-pairs/
/// Author : liuyubobobo
/// Time   : 2022-07-23

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> cols(n, vector<int>(n));
        for(int j = 0; j < n; j ++)
            for(int i = 0; i < n; i ++) cols[j][i] = grid[i][j];

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                res += grid[i] == cols[j];
        return res;
    }
};


int main() {

    return 0;
}
