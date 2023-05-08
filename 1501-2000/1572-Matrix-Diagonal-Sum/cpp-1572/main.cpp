/// Source : https://leetcode.com/problems/matrix-diagonal-sum/
/// Author : liuyubobobo
/// Time   : 2023-05-07

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int n = mat.size(), sum = 0;
        for(int i = 0; i < n; i ++)
            sum += mat[i][i] + mat[i][n - 1 - i];
        if(n & 1) sum -= mat[n / 2][n / 2];
        return sum;
    }
};


int main() {

    return 0;
}
