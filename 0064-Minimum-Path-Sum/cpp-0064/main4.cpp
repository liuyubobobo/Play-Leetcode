/// Source : https://leetcode.com/problems/minimum-path-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-21

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
/// with O(1) space, get the answer based on the original space
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        assert(n > 0);

        int m = grid[0].size();
        assert(m > 0);

        for(int j = 1 ; j < m ; j ++)
            grid[0][j] += grid[0][j-1];

        for(int i = 1 ; i < n ; i ++)
            grid[i][0] += grid[i-1][0];

        for(int i = 1 ; i < n ; i ++)
            for(int j = 1 ; j < m ; j ++)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);

        return grid[n-1][m-1];
    }
};

int main() {

    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}