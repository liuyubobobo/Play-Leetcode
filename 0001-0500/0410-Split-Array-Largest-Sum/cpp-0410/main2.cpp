/// Source : https://leetcode.com/problems/split-array-largest-sum/
/// Author : liuyubobobo
/// Time   : 2020-05-11

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n * n * m)
/// Space Complexity: O(n * m)
class Solution {

public:
    int splitArray(vector<int>& nums, int m) {

        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for(int i = 0; i < n; i ++)
            pre[i + 1] = pre[i] + nums[i];

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int start = 0; start < n; start ++)
            dp[0][start] = pre[n] - pre[start];

        for(int k = 1; k < m; k ++)
            for(int start = 0; start < n; start ++)
                for(int i = start; i + k < n; i ++)
                    dp[k][start] = min(dp[k][start], max((int)(pre[i + 1] - pre[start]), dp[k - 1][i + 1]));
        return dp[m - 1][0];
    }
};


int main() {

    vector<int> nums = {7, 2, 5, 10, 8};
    cout << Solution().splitArray(nums, 2) << endl;
    // 18

    return 0;
}
