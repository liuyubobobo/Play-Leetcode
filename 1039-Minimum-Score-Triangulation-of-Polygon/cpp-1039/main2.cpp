/// Source : https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
/// Author : liuyubobobo
/// Time   : 2019-05-19

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(|A|^3)
/// Space Complexity: O(|A|^2)
class Solution {

public:
    int minScoreTriangulation(vector<int>& A) {

        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i + 2 < n; i ++)
            dp[i][i + 2] = A[i] * A[i + 1] * A[i + 2];

        for(int len = 4; len <= n; len ++)
            for(int i = 0; i + len - 1 < n; i ++){

                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for(int k = i + 1; k < j; k ++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
            }
        return dp[0][n - 1];
    }
};


int main() {

    vector<int> A1 = {1, 2, 3};
    cout << Solution().minScoreTriangulation(A1) << endl;
    // 6

    vector<int> A2 = {3, 7, 4, 5};
    cout << Solution().minScoreTriangulation(A2) << endl;
    // 144

    vector<int> A3 = {1, 3, 1, 4, 1, 5};
    cout << Solution().minScoreTriangulation(A3) << endl;
    // 13

    return 0;
}