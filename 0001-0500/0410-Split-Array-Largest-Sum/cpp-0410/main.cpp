/// Source : https://leetcode.com/problems/split-array-largest-sum/
/// Author : liuyubobobo
/// Time   : 2020-05-11

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memory Search
/// Time Complexity: O(n * n * m)
/// Space Complexity: O(n * m)
class Solution {

private:
    int n;

public:
    int splitArray(vector<int>& nums, int m) {

        n = nums.size();
        vector<long long> pre(n + 1, 0);
        for(int i = 0; i < n; i ++)
            pre[i + 1] = pre[i] + nums[i];

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(nums, m - 1, 0, pre, dp);
    }

private:
    int dfs(const vector<int>& nums, int m, int start,
            const vector<long long>& pre, vector<vector<int>>& dp){

        if(dp[m][start] != -1) return dp[m][start];
        if(m == 0) return dp[m][start] = pre[n] - pre[start];

        int res = INT_MAX;
        for(int i = start; i + m < n; i ++)
            res =min(res, max((int)(pre[i + 1] - pre[start]), dfs(nums, m - 1, i + 1, pre, dp)));
        return dp[m][start] = res;
    }
};


int main() {

    vector<int> nums = {7, 2, 5, 10, 8};
    cout << Solution().splitArray(nums, 2) << endl;
    // 18

    return 0;
}
