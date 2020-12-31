/// Source : https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
/// Author : liuyubobobo
/// Time   : 2019-07-20

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {

private:
    int n;

public:
    int mctFromLeafValues(vector<int>& arr) {

        n = arr.size();
        vector<vector<int>> maxv(n,vector<int>(n));
        for(int i = 0; i < n; i ++) maxv[i][i] = arr[i];
        for(int d = 1; d < n; d ++)
            for(int i = 0; i + d < n; i ++)
                maxv[i][i + d] = max(maxv[i][i + d - 1], maxv[i + 1][i + d]);

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return search(arr, 0, n - 1, maxv, dp);
    }

    int search(const vector<int>& arr, int l, int r,
               vector<vector<int>>& maxv, vector<vector<int>>& dp){

        if(l == r)
            return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int res = INT_MAX;
        for(int mid = l; mid < r; mid ++){
            int lres = search(arr, l, mid, maxv, dp);
            int rres = search(arr, mid + 1, r, maxv, dp);
            res = min(res, lres + rres + maxv[l][mid] * maxv[mid + 1][r]);
        }

        return dp[l][r] = res;
    }
};


int main() {

    vector<int> vec = {6, 2, 4};
    cout << Solution().mctFromLeafValues(vec) << endl;
    // 32

    return 0;
}