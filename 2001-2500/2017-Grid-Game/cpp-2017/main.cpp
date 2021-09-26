/// Source : https://leetcode.com/problems/grid-game/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int n = grid[0].size();
        vector<vector<long long>> presum(2, vector<long long>(n + 1, 0ll));
        for(int r = 0; r < 2; r ++)
            for(int i = 0; i < n; i ++)
                presum[r][i + 1] = presum[r][i] + grid[r][i];

        long long res = LONG_LONG_MAX;
        for(int i = 0; i < n; i ++)
            res = min(res, max(presum[0][n] - presum[0][i + 1], presum[1][i]));
        return res;
    }
};


int main() {

    vector<vector<int>> grid1 = {{2, 5, 4}, {1, 5, 1}};
    cout << Solution().gridGame(grid1) << endl;
    // 4

    vector<vector<int>> grid2 = {{3, 3, 1}, {8, 5, 2}};
    cout << Solution().gridGame(grid1) << endl;
    // 4

    vector<vector<int>> grid3 = {{1, 3, 1, 15}, {1, 3, 3, 1}};
    cout << Solution().gridGame(grid3) << endl;
    // 7

    return 0;
}
