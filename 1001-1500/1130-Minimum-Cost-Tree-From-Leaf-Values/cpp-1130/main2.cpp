/// Source : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
/// Author : liuyubobobo
/// Time   : 2019-08-22

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {

public:
    int mctFromLeafValues(vector<int>& arr) {

        int n = arr.size();
        vector<vector<int>> maxv(n,vector<int>(n));
        for(int i = 0; i < n; i ++) maxv[i][i] = arr[i];
        for(int d = 1; d < n; d ++)
            for(int i = 0; i + d < n; i ++)
                maxv[i][i + d] = max(maxv[i][i + d - 1], maxv[i + 1][i + d]);

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i ++) dp[i][i] = 0;
        for(int d = 1; d < n; d ++)
            for(int i = 0; i + d < n; i ++)
                for(int mid = i; mid < i + d; mid ++)
                    dp[i][i + d] = min(dp[i][i + d], dp[i][mid] + dp[mid + 1][i + d] + maxv[i][mid] * maxv[mid + 1][i + d]);
        return dp[0][n - 1];
    }
};


int main() {

    vector<int> vec1 = {6, 2, 4};
    cout << Solution().mctFromLeafValues(vec1) << endl;
    // 32

    vector<int> vec2 = {7, 12, 8, 10};
    cout << Solution().mctFromLeafValues(vec2) << endl;
    // 284

    return 0;
}