/// Source : https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Presum + HashMap
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> presum(R + 1, vector<int>(C, 0));
        for(int j = 0; j < C; j ++)
            for(int i = 0; i < R; i ++)
                presum[i + 1][j] = presum[i][j] + matrix[i][j];

        int res = 0;
        for(int r1 = 0; r1 < R; r1 ++)
            for(int r2 = r1; r2 < R; r2 ++){

                unordered_map<int, int> table;
                table[0] ++;
                int sum = 0;
                for(int c = 0; c < C; c ++){
                    sum += presum[r2 + 1][c] - presum[r1][c];
                    res += table[sum - target];
                    table[sum] ++;
                }
            }
        return res;
    }
};


int main() {

    return 0;
}
