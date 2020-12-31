/// Source : https://leetcode.com/problems/minimum-path-sum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-21

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
/// with O(n) space, just n space.
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        assert(n > 0);

        int m = grid[0].size();
        assert(m > 0);

        vector<int> res(m, 0);
        res[0] = grid[0][0];

        for(int j = 1 ; j < m ; j ++)
            res[j] = grid[0][j] + res[j-1];

        for(int i = 1 ; i < n ; i ++){
            res[0] += grid[i][0];
            for(int j = 1 ; j < m ; j ++)
                res[j] = grid[i][j] + min(res[j], res[j-1]);
        }

        return res[m-1];
    }
};

int main() {

    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << Solution().minPathSum(grid) << endl;

    return 0;
}