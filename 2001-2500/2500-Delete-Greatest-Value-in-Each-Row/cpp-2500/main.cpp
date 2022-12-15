/// Source : https://leetcode.com/problems/delete-greatest-value-in-each-row/
/// Author : liuyubobobo
/// Time   : 2022-12-10

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Simulation
/// Time Complexity: O(R * ClogC)
/// Space Complexity: O(1)
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {

        for(vector<int>& row: grid) sort(row.begin(), row.end());

        int res = 0;
        for(int j = grid[0].size() - 1; j >= 0; j --){
            int maxv = 0;
            for(int i = 0; i < grid.size(); i ++) maxv = max(maxv, grid[i][j]);
            res += maxv;
        }
        return res;
    }
};


int main() {

    return 0;
}
