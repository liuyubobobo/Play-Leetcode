/// Source : https://leetcode.com/problems/burst-balloons/
/// Author : liuyubobobo
/// Time   : 2020-05-08

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(nums, 0, n - 1, dp);
    }

private:
    int dfs(const vector<int>& nums, int l, int r, vector<vector<int>>& dp){

        if(l == r) return dp[l][r] = 0;
        if(dp[l][r] != -1) return dp[l][r];

        int res = 0;
        for(int k = l + 1; k <= r - 1; k ++)
            res = max(res, dfs(nums, l, k, dp) + dfs(nums, k, r, dp) + nums[l] * nums[k] * nums[r]);
        return dp[l][r] = res;
    }
};


int main() {

    vector<int> nums = {3,1,5,8};
    cout << Solution().maxCoins(nums) << endl;
    // 167

    return 0;
}
