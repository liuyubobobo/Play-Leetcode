/// Source : https://leetcode.com/problems/spiral-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-04-24

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

private:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int N, M;

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        N = matrix.size();
        if(N == 0)
            return {};

        M = matrix[0].size();
        if(M == 0)
            return {};

        vector<vector<bool>> visited(N, vector<bool>(M, false));
        int curd = 0, curx = 0, cury = 0;
        vector<int> res;
        while(res.size() < N * M){

            if(!visited[curx][cury]) {
                res.push_back(matrix[curx][cury]);
                visited[curx][cury] = true;
            }

            int nextx = curx + d[curd][0];
            int nexty = cury + d[curd][1];
            if(inArea(nextx, nexty) && !visited[nextx][nexty]){
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
        return x >= 0 && x < N && y >= 0 && y < M;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> matrix1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    print_vec(Solution().spiralOrder(matrix1));

    return 0;
}