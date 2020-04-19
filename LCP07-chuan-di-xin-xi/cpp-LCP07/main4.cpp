/// Source : https://leetcode-cn.com/problems/chuan-di-xin-xi/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>

using namespace  std;


/// Methematics: Matrix Multiplication
/// Time Complexity: O(k * n^3)
/// Space Complexity: O(n^2)
class Solution {

public:
    int numWays(int n, vector<vector<int>>& relation, int k) {

        vector<vector<int>> A(n, vector<int>(n, 0));
        for(const vector<int>& arc: relation)
            A[arc[0]][arc[1]] = 1;

        vector<vector<int>> res = A;
        for(int i = 1; i < k; i ++) res = mul(res, A, n);
        return res[0][n - 1];
    }

private:
    vector<vector<int>> mul(const vector<vector<int>>& A,
                            const vector<vector<int>>& B,int n){

        vector<vector<int>> res(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                for(int k = 0; k < n; k ++)
                    res[i][j] += A[i][k] * B[k][j];
        return res;
    }
};


int main() {

    return 0;
}
