/// Source : https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
/// Author : liuyubobobo
/// Time   : 2019-05-04

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(|A|^3)
/// Space Complexity: O(|A|^2)
class Solution {

public:
    int minScoreTriangulation(vector<int>& A) {

        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(A, 0, n - 1, dp);
    }

private:
    int dfs(const vector<int>& A, int i, int j,
            vector<vector<int>>& dp){

        if(i + 2 > j) return 0;
        if(i + 2 == j) return A[i] * A[i + 1] * A[i + 2];

        if(dp[i][j] != -1) return dp[i][j];

        int res = INT_MAX;
        for(int k = i + 1; k < j; k ++)
            res = min(res, dfs(A, i, k, dp) + dfs(A, k, j, dp) + A[i] * A[j] * A[k]);
        return dp[i][j] = res;
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