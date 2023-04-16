/// Source : https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(R * C * log(max(grid[i][j])))
/// Space Complexity: O(C)
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        vector<int> res(C, 0);
        for(int j = 0; j < C; j ++){
            for(int i = 0; i < R; i ++){
                string s = to_string(grid[i][j]);
                res[j] = max(res[j], (int)s.size());
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
