/// Source : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/submissions/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(R * C)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int R = rowSum.size(), C = colSum.size();
        vector<vector<int>> res(R, vector<int>(C, 0));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        return res;
    }
};


int main() {

    return 0;
}
