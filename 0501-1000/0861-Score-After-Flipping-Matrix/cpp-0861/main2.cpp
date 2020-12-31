/// Source : https://leetcode.com/problems/score-after-flipping-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-06-30

#include <iostream>
#include <vector>

using namespace std;

/// Greedy
///
/// An unbelievable concise implementation to the same concept of this problem
///
/// We make the left most digit of every row into 0 by xor A[r][0],
/// After that, we can of course toggling the entire column to get all the left most digit to 1,
///
/// Since we make every left most digit is 0, it means we need to toggle every row if the original left most digit is 1
/// We make every element to xor the original leftmost digit in the same row,
/// If the leftmost digit is 1, we need to toggle it, A[r][c] ^ 1 means toggle it! Since 0^1 = 1 and 1^1 = 0;
/// If the leftmost digit is 0, we don't need to toggle it, A[r][c] ^ 0 means stick to the original digit.
/// The col variable record the one number if we don't toggle the column, just toggle the needed rows if we want to keep all the leftmost digits zero;
/// The R - col variable record the one number if we toggle the column:)
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

public:
    int matrixScore(vector<vector<int>>& A) {

        int R = A.size(), C = A[0].size();
        int ans = 0;
        for (int c = 0; c < C; c ++) {
            int col = 0;
            for (int r = 0; r < R; r ++)
                col += A[r][c] ^ A[r][0];
            ans += max(col, R - col) * (1 << (C - 1 - c));
        }
        return ans;
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