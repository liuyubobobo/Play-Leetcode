/// Source : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
/// Author : liuyubobobo
/// Time   : 2019-02-15

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int res = 0;
        for(int i = 0; i < grid.size(); i ++)
            for(int e: grid[i]) res += (e < 0);
        return res;
    }
};


int main() {

    return 0;
}
