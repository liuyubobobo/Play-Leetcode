/// Source : https://leetcode.com/problems/minimum-path-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-21

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
/// with O(n^2) space
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        assert(n > 0);

        int m = grid[0].size();
        assert(m > 0);

        vector<vector<int>> res = grid;

        for(int j = 1 ; j < m ; j ++)
            res[0][j] += res[0][j-1];

        for(int i = 1 ; i < n ; i ++)
            res[i][0] += res[i-1][0];

        for(int i = 1 ; i < n ; i ++)
            for(int j = 1 ; j < m ; j ++)
                res[i][j] += min(res[i-1][j], res[i][j-1]);

        return res[n-1][m-1];
    }
};

int main() {

    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}