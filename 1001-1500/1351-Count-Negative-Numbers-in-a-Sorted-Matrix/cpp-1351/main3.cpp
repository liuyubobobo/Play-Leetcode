/// Source : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
/// Author : liuyubobobo
/// Time   : 2019-02-16

#include <iostream>
#include <vector>

using namespace std;


/// Search Break Points
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int res = 0, m = grid.size(), n = grid[0].size();
        int c = n - 1;
        for(int r = 0; r < m; r ++){
            while(c >= 0 && grid[r][c] < 0) c --;
            res += (n - c - 1);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> g1 = {{5, 1, 0}, {-5, -5, -5}};
    cout << Solution().countNegatives(g1) << endl;

    return 0;
}
