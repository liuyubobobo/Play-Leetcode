/// Source : https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
/// Author : liuyubobobo
/// Time   : 2021-06-05

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {

        for(int i = 0; i < 4; i ++){
            mat = rotate(mat);
//            for(const vector<int>& row: mat){
//                for(int e: row) cout << e << " ";
//                cout << endl;
//            }
//            cout << endl;

            if(mat == target) return true;
        }
        return false;
    }

private:
    vector<vector<int>> rotate(const vector<vector<int>>& M){

        int n = M.size();
        vector<vector<int>> res(n, vector<int>(n));

        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                res[j][n - 1 - i] = M[i][j];
        return res;
    }
};


int main() {

    vector<vector<int>> mat3 = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> target3 = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    cout << Solution().findRotation(mat3, target3) << endl;
    // 1

    return 0;
}
