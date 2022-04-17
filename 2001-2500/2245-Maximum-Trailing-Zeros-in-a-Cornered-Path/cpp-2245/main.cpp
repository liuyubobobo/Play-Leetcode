/// Source : https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        vector<vector<int>> two(R, vector<int>(C, 0)), five(R, vector<int>(C, 0));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                int num = grid[i][j];
                int two_num = 0, five_num = 0;
                while(num % 2 == 0) two_num ++, num /= 2;
                while(num % 5 == 0) five_num ++, num /= 5;
                two[i][j] = two_num;
                five[i][j] = five_num;
            }

        vector<vector<int>> presum_row_two(R, vector<int>(C + 1, 0)), presum_row_five(R, vector<int>(C + 1, 0));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                presum_row_two[i][j + 1] = presum_row_two[i][j] + two[i][j];
                presum_row_five[i][j + 1] = presum_row_five[i][j] + five[i][j];
            }

        vector<vector<int>> presum_col_two(R + 1, vector<int>(C, 0)), presum_col_five(R + 1, vector<int>(C, 0));
        for(int j = 0; j < C; j ++)
            for(int i = 0; i < R; i ++){
                presum_col_two[i + 1][j] = presum_col_two[i][j] + two[i][j];
                presum_col_five[i + 1][j] = presum_col_five[i][j] + five[i][j];
            }

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                int up_two = presum_col_two[i][j], up_five = presum_col_five[i][j];
                int down_two = presum_col_two[R][j] - presum_col_two[i + 1][j], down_five = presum_col_five[R][j] - presum_col_five[i + 1][j];
                int left_two = presum_row_two[i][j], left_five = presum_row_five[i][j];
                int right_two = presum_row_two[i][C] - presum_row_two[i][j + 1], right_five = presum_row_five[i][C] - presum_row_five[i][j + 1];

                res = max(res, min(up_two + left_two + two[i][j], up_five + left_five + five[i][j]));
                res = max(res, min(up_two + right_two + two[i][j], up_five + right_five + five[i][j]));
                res = max(res, min(down_two + left_two + two[i][j], down_five + left_five + five[i][j]));
                res = max(res, min(down_two + right_two + two[i][j], down_five + right_five + five[i][j]));
            }
        return res;
    }
};


int main() {

    vector<vector<int>> grid1 = {{23,17,15,3,20},{8,1,20,27,11},{9,4,6,2,21},{40,9,1,10,6},{22,7,4,5,3}};
    cout << Solution().maxTrailingZeros(grid1) << '\n';
    // 3

    vector<vector<int>> grid2 = {{4,3,2},{7,6,1},{8,8,8}};
    cout << Solution().maxTrailingZeros(grid2) << '\n';
    // 0

    vector<vector<int>> grid3 = {{10}, {6}, {15}};
    cout << Solution().maxTrailingZeros(grid3) << '\n';
    // 2

    return 0;
}
