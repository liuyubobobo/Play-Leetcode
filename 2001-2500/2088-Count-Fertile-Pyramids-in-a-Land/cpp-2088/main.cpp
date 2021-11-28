/// Source : https://leetcode.com/problems/count-fertile-pyramids-in-a-land/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// DP + Two Pointers
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        vector<vector<int>> A(R, vector<int>(C, 0));
        vector<int> left(C, 0), right(C, 0);
        for(int i = 0; i < R; i ++){
            left[0] = grid[i][0];
            for(int j = 1; j < C; j ++)
                left[j] = (grid[i][j] ? left[j - 1] + 1 : 0);

            right[C - 1] = grid[i][C - 1];
            for(int j = C - 2; j >= 0; j --)
                right[j] = (grid[i][j] ? right[j + 1] + 1 : 0);

            for(int j = 0; j < C; j ++) A[i][j] = min(left[j], right[j]);
        }

//        for(int i = 0; i < R; i ++){
//            for(int j = 0; j < C; j ++) cout << A[i][j] << ' ';
//            cout << '\n';
//        }

        int res = 0;
        for(int j = 1; j + 1 < C; j ++){
            vector<int> v(R);
            for(int i = 0; i < R; i ++) v[i] = A[i][j];
            res += solve(R, v);

            reverse(v.begin(), v.end());
            res += solve(R, v);
        }

        return res;
    }

private:
    int solve(int n, const vector<int>& v){

        int res = 0;
        for(int start = 0, end = 0; start < n; start ++){
            if(v[start] == 0) continue;
            if(end < start) end = start;
            while(end < n && v[end] >= end - start + 1) end ++;
            if(end - start > 1) res += end - start - 1;
        }
        return res;
    }
};

int main() {

    vector<vector<int>> grid1 = {{0, 1, 1, 0}, {1, 1, 1, 1}};
    cout << Solution().countPyramids(grid1) << endl;
    // 2

    vector<vector<int>> grid2 = {{1, 1, 1}, {1, 1, 1}};
    cout << Solution().countPyramids(grid2) << endl;
    // 2

    vector<vector<int>> grid3 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    cout << Solution().countPyramids(grid3) << endl;
    // 0

    vector<vector<int>> grid4 = {{1,1,1,1,0}, {1,1,1,1,1}, {1,1,1,1,1}, {0,1,0,0,1}};
    cout << Solution().countPyramids(grid4) << endl;
    // 13

    return 0;
}
