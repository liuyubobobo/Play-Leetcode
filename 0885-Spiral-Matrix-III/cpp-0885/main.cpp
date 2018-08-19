/// Source : https://leetcode.com/problems/spiral-matrix-iii/description/
/// Author : liuyubobobo
/// Time   : 2018-08-11

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(max(R, C)^2)
/// Space Complexity: O(R * C)
class Solution {

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {

        vector<vector<int>> ret = {{r0, c0}};

        int res = 1, posx = r0, posy = c0;
        int curD = 0, curSide = 1;
        while(res < R * C){

            for(int i = 0 ; i < 2; i ++){
                for(int j = 0; j < curSide; j ++){
                    posx = posx + d[curD][0];
                    posy = posy + d[curD][1];
                    if(inArea(posx, posy, R, C)){
                        ret.push_back({posx, posy});
                        res ++;
                    }
                }
                curD = (curD + 1) % 4;
            }
            curSide ++;
        }

        return ret;
    }

private:
    bool inArea(int x, int y, int R, int C){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


int main() {

    return 0;
}