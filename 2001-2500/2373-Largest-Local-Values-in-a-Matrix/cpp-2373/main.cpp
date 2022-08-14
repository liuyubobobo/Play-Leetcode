/// Source : https://leetcode.com/problems/largest-local-values-in-a-matrix/
/// Author : liuyubobobo
/// Time   : 2022-08-13

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for(int i = 1; i + 1 < n; i ++)
            for(int j = 1; j + 1 < n; j ++){
                int t = 0;
                for(int d1 = -1; d1 <= 1; d1 ++)
                    for(int d2 = -1; d2 <= 1; d2 ++)
                        t = max(t, grid[i + d1][j + d2]);
                res[i - 1][j - 1] = t;
            }
        return res;
    }
};


int main() {

    return 0;
}
