/// Source : https://leetcode.com/problems/remove-boxes/
/// Author : liuyubobobo
/// Time   : 2021-08-15

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^4)
/// Space Complexity: O(n^3)
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {

        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return dfs(boxes, 0, n - 1, 0, dp);
    }

private:
    int dfs(const vector<int>& boxes, int l, int r, int k, vector<vector<vector<int>>>& dp){

        if(l > r) return 0;

        if(dp[l][r][k] != -1) return dp[l][r][k];

        int res = dfs(boxes, l, r - 1, 0, dp) + (k + 1) * (k + 1);

        for(int i = l; i < r; i ++)
            if(boxes[i] == boxes[r])
                res = max(res, dfs(boxes, l, i, k + 1, dp) + dfs(boxes, i + 1, r - 1, 0, dp));
        return dp[l][r][k] = res;
    }
};


int main() {

    vector<int> boxes1 = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    cout << Solution().removeBoxes(boxes1) << endl;
    // 23

    vector<int> boxes2 = {1, 1, 1};
    cout << Solution().removeBoxes(boxes2) << endl;
    // 9

    vector<int> boxes3 = {1};
    cout << Solution().removeBoxes(boxes3) << endl;
    // 1

    return 0;
}
