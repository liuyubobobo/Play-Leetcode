/// Source : https://leetcode.com/problems/image-smoother/
/// Author : liuyubobobo
/// Time   : 2022-03-23

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(R * C)
/// Space Complexity: O(1)
class Solution {
private:
    int R, C;

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        R = img.size(), C = img[0].size();
        vector<vector<int>> res(R, vector<int>(C));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                int sum = 0, cnt = 0;
                for(int r = -1; r <= 1; r ++)
                    for(int c = -1; c <= 1; c ++)
                        if(in_area(i + r, j + c))
                            sum += img[i + r][j + c], cnt ++;
                res[i][j] = sum / cnt;
            }
        return res;
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
