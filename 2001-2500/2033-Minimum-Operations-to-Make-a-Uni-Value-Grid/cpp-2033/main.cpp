/// Source : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
/// Author : liuyubobobo
/// Time   : 2021-10-09

#include <iostream>
#include <vector>

using namespace std;


/// Go to median
/// Time Complexity: O(R * C * log(R * C))
/// Space Complexity: O()
class Solution {

private:
    int R, C;

public:
    int minOperations(vector<vector<int>>& grid, int x) {

        R = grid.size(), C = grid[0].size();

        int len = R * C;
        vector<int> A;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                A.push_back(grid[i][j]);

        sort(A.begin(), A.end());

        if(len % 2 == 1)
            return solve(grid, x, A[len / 2]);

        int tres = solve(grid, x, A[len / 2]);
        if(tres != -1) return tres;
        return solve(grid, x, A[(len - 1) / 2]);
    }

private:
    int solve(const vector<vector<int>>& grid, int x, int t){

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                int k = abs(grid[i][j] - t);
                if(k % x) return -1;
                res += k / x;
            }
        return res;
    }
};


int main() {

    return 0;
}
