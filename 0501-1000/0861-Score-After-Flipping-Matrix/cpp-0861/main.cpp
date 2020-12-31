/// Source : https://leetcode.com/problems/score-after-flipping-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-06-30

#include <iostream>
#include <vector>

using namespace std;

/// Greedy
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

public:
    int matrixScore(vector<vector<int>>& A) {

        for(int i = 0 ; i < A.size() ; i ++)
            if(A[i][0] == 0)
                flipRow(A, i);

        for(int j = 1 ; j < A[0].size() ; j ++){

            int zeros = zeroNumInCol(A, j);
            if(zeros > A.size() / 2)
                flipCol(A, j);
        }

//        for(int i = 0 ; i < A.size() ; i ++)
//            for(int j = 0 ; j < A[i].size() ; j ++)
//                cout << A[i][j] << (j == A[i].size() - 1 ? '\n' : ' ');

        return score(A);
    }

private:
    int score(const vector<vector<int>>& A){
        int res = 0;
        for(int i = 0 ; i < A.size() ; i ++)
            for(int j = 0 ; j < A[i].size() ; j ++)
                if(A[i][j])
                    res += (1 << (A[i].size() - 1 - j));
        return res;
    }

    void flipRow(vector<vector<int>>& A, int row){
        for(int j = 0 ; j < A[row].size() ; j ++)
            A[row][j] = 1 - A[row][j];
    }

    void flipCol(vector<vector<int>>& A, int col){
        for(int i = 0 ; i < A.size() ; i ++)
            A[i][col] = 1 - A[i][col];
    }

    int zeroNumInCol(const vector<vector<int>>& A, int col){
        int zeros = 0;
        for(int i = 0 ; i < A.size() ; i ++)
            zeros += (A[i][col] == 0 ? 1 : 0);
        return zeros;
    }
};


int main() {

    vector<vector<int>> A1 = {
            {0, 0, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 0}
    };
    cout << Solution().matrixScore(A1) << endl;

    return 0;
}