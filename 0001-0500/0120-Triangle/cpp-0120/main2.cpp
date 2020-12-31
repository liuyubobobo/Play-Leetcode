/// Source : https://leetcode.com/problems/triangle/description/
/// Author : liuyubobobo
/// Time   : 2018-12-19

#include <iostream>
#include <vector>

using namespace std;

/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i = 0 ; i < n ; i ++)
            go(triangle, n - 1, i, dp);

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }

private:
    int go(const vector<vector<int>>& triangle, int i, int j,
           vector<vector<int>>& dp){

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i == 0)
            return dp[i][j] = triangle[i][j];

        if(j == 0)
            return dp[i][j] = triangle[i][j] + go(triangle, i - 1, 0, dp);

        if(j == i)
            return dp[i][j] = triangle[i][j] + go(triangle, i - 1, i - 1, dp);

        return dp[i][j] = triangle[i][j] + min(go(triangle, i - 1, j - 1, dp),
                                               go(triangle, i - 1, j, dp));
    }
};


int main() {

    vector<vector<int>> triangle = { {2},
                                     {3, 4},
                                     {6,5,7},
                                     {4,1,8,3}};
    cout << Solution().minimumTotal(triangle) << endl;
    // 11

    return 0;
}