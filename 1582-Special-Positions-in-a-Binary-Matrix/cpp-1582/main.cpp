/// Source : https://leetcode.com/problems/special-positions-in-a-binary-matrix/
/// Author : liuyubobobo
/// Time   : 2020-09-12

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int R = mat.size(), C = mat[0].size(), res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(mat[i][j] && special(mat, i, j, R, C)) res ++;
        return res;
    }

private:
    bool special(const vector<vector<int>>& mat, int x, int y, int R, int C){

        for(int i = 0; i < R; i ++)
            if(i != x && mat[i][y] == 1) return false;

        for(int j = 0; j < C; j ++)
            if(j != y && mat[x][j] == 1) return false;

        return true;
    }
};


int main() {

    vector<vector<int>> mat1 = {{1,0,0}, {0,0,1},{1,0,0}};
    cout << Solution().numSpecial(mat1) << endl;
    // 1

    vector<vector<int>> mat2 = {{1,0,0}, {0,1,0},{0,0,1}};
    cout << Solution().numSpecial(mat2) << endl;
    // 3

    vector<vector<int>> mat3 = {{0,0,0,1}, {1,0,0,0},{0,1,1,0},{0, 0, 0, 0}};
    cout << Solution().numSpecial(mat3) << endl;
    // 2

    vector<vector<int>> mat4 = {{0,0,0,0,0}, {1,0,0,0,0},{0,1,0,0,0},{0, 0, 1,0, 0}, {0,0,0,1,1}};
    cout << Solution().numSpecial(mat4) << endl;
    // 3

    vector<vector<int>> mat5 = {{0,0,1,0}, {0,0,0,0},{0,0,0,0},{0, 1,0, 0}};
    cout << Solution().numSpecial(mat5) << endl;
    // 2

    return 0;
}
