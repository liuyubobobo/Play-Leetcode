/// Source : https://leetcode.com/problems/special-positions-in-a-binary-matrix/
/// Author : liuyubobobo
/// Time   : 2020-10-16

#include <iostream>
#include <vector>

using namespace std;


/// Two Passes
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int R = mat.size(), C = mat[0].size();
        vector<int> row(R, 0), col(C, 0);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(mat[i][j]) row[i] ++, col[j] ++;

        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(mat[i][j] && row[i] == 1 && col[j] == 1)
                    res ++;
        return res;
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
