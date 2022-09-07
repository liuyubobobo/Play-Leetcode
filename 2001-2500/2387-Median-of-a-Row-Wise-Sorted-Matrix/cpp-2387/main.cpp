/// Source : https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/
/// Author : liuyubobobo
/// Time   : 2022-09-07

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(R * logC * log(maxv))
/// Space Complexity: O(1)
class Solution {

public:
    int matrixMedian(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        int n = (R * C + 1) / 2;

        int l = 1, r = 1e6;
        while(l < r){
            int mid = (l + r) / 2;
            if(less_than_or_equal_to(R, grid, mid) < n) l = mid + 1;
            else r = mid;
        }
        return l;
    }

private:
    int less_than_or_equal_to(int R, const vector<vector<int>>& grid, int v){

        int res = 0;
        for(int i = 0; i < R; i ++){
            res += upper_bound(grid[i].begin(), grid[i].end(), v) - grid[i].begin();
        }
        return res;
    }
};


int main() {

    return 0;
}
