/// Source : https://leetcode.com/problems/spiral-matrix-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-04-24

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int N;

public:
    vector<vector<int>> generateMatrix(int n) {

        if(n == 0)
            return {};

        N = n;
        int maxnum = n * n;

        vector<vector<int>> res(N, vector<int>(N, 0));
        int curx = 0, cury = 0, curd = 0, num = 1;
        while(num <= maxnum){
            if(res[curx][cury] == 0){
                res[curx][cury] = num;
                num ++;
            }

            int nextx = curx + d[curd][0];
            int nexty = cury + d[curd][1];
            if(inArea(nextx, nexty) && res[nextx][nexty] == 0){
                curx = nextx;
                cury = nexty;
            }
            else
                curd = (curd + 1) % 4;
        }

        return res;
    }

private:
    bool inArea(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < N;
    }
};


void print_matrix(const vector<vector<int>>& matrix){
    for(const vector<int>& vec: matrix){
        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
}

int main() {

    vector<vector<int>> res = Solution().generateMatrix(3);
    print_matrix(res);

    return 0;
}