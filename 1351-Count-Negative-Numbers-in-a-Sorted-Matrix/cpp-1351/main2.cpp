/// Source : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
/// Author : liuyubobobo
/// Time   : 2019-02-16

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(m * logn)
/// Space Complexity: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int res = 0;
        for(int i = 0; i < grid.size(); i ++)
            res += upper_bound(grid[i].rbegin(), grid[i].rend(), -1) - grid[i].rbegin();
        return res;
    }
};


int main() {

    return 0;
}
