/// Source : https://leetcode.cn/contest/zj-future2022/problems/kflZMc/
/// Author : liuyubobobo
/// Time   : 2022-07-19

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window in 2D
/// Time Complexity: O(R * C)
/// Space Complexity: O(R + C)
class Solution {
public:
    int buildTransferStation(vector<vector<int>>& area) {

        int R = area.size(), C = area[0].size();

        vector<int> rows(R, 0), cols(C, 0);
        int total = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(area[i][j]) rows[i] ++, cols[j] ++, total ++;

        vector<int> pre_rows(R, rows[0]), pre_cols(C, cols[0]);
        for(int i = 1; i < R; i ++) pre_rows[i] = pre_rows[i - 1] + rows[i];
        for(int j = 1; j < C; j ++) pre_cols[j] = pre_cols[j - 1] + cols[j];

        int prow = 0;
        for(int i = 1; i < R; i ++) prow += rows[i] * i;
        vector<int> row_res(R, prow);
        for(int i = 1; i < R; i ++){
            int crow = prow + pre_rows[i - 1] - (total - pre_rows[i - 1]);
            row_res[i] = crow;
            prow = crow;
        }

        int pcol = 0;
        for(int j = 1; j < C; j ++) pcol += cols[j] * j;
        vector<int> col_res(C, pcol);
        for(int j = 1; j < C; j ++){
            int ccol = pcol + pre_cols[j - 1] - (total - pre_cols[j - 1]);
            col_res[j] = ccol;
            pcol = ccol;
        }

        return *min_element(row_res.begin(), row_res.end()) + *min_element(col_res.begin(), col_res.end());
    }
};


int main() {

    vector<vector<int>> area1 = {
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0}
    };
    cout << Solution().buildTransferStation(area1) << '\n';
    // 5

    return 0;
}
