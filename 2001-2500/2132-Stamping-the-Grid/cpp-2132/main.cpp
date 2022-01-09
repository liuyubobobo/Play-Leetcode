/// Source : https://leetcode.com/problems/stamping-the-grid/
/// Author : liuyubobobo
/// Time   : 2022-01-08

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int H, int W) {

        int R = grid.size(), C = grid[0].size();
        vector<vector<int>> presum(R + 1, vector<int>(C + 1, 0));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                presum[i + 1][j + 1] = presum[i + 1][j] + presum[i][j + 1] + grid[i][j] - presum[i][j];

        vector<vector<int>> draw(R, vector<int>(C, 0));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(!grid[i][j]){
                    if(draw[i][j] == 0){
                        if(i + H - 1 >= R || j + W - 1 >= C ||
                           presum[i + H][j + W] - presum[i + H][j] - presum[i][j + W] + presum[i][j])
                            return false;

                        for(int ii = 0; ii < H && draw[i + ii][j] == 0; ii ++)
                            for(int jj = 0; jj < W && draw[i + ii][j + jj] == 0; jj ++)
                                draw[i + ii][j + jj] = 1;
                    }
                    else if(i + H - 1 < R && j + W - 1 < C &&
                            presum[i + H][j + W] - presum[i + H][j] - presum[i][j + W] + presum[i][j] == 0){

                        for(int ii = H - 1; ii >= 0 && draw[i + ii][j + W - 1] == 0; ii --)
                            for(int jj = W - 1; jj >= 0 && draw[i + ii][j + jj] == 0; jj --)
                                draw[i + ii][j + jj] = 1;
                    }
                }
        return true;
    }
};


int main() {

    return 0;
}
