/// Source : https://leetcode.com/problems/minimum-falling-path-sum/
/// Author : liuyubobobo
/// Time   : 2018-10-27

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m * n)
/// Space Complexity: O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {

        int m = A.size();
        if(m == 0) return 0;

        int n = A[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        dp[0] = A[0];
        for(int i = 1; i < m; i ++)
            for(int j = 0; j < n; j ++)
                for(int k = max(j - 1, 0); k <= min(n - 1, j + 1); k ++)
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + A[i][j]);

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};


int main() {

    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    cout << Solution().minFallingPathSum(A) << endl;
    // 12

    return 0;
}