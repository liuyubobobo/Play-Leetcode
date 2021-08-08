/// Source : https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/
/// Author : liuyubobobo
/// Time   : 2021-08-07

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n * n * k)
/// Space Complexity: O(n * k)
class Solution {

private:
    const int INF = 1e9;

public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {

        int n = nums.size();

        vector<vector<int>> dp(k + 1, vector<int>(n, -1));
        return dfs(nums, k, 0, dp);
    }

private:
    int dfs(const vector<int>& nums, int k, int index, vector<vector<int>>& dp){

        if(index == nums.size()) return 0;
        if(k < 0) return INF;
        if(dp[k][index] != -1) return dp[k][index];

        int maxv = 0, sum = 0, res = INF;
        for(int i = index; i < nums.size(); i ++){
            maxv = max(maxv, nums[i]);
            sum += nums[i];
            res = min(res, maxv * (i - index + 1) - sum + dfs(nums, k - 1, i + 1, dp));
        }
        return dp[k][index] = res;
    }
};


int main() {

    vector<int> nums1 = {10, 20};
    cout << Solution().minSpaceWastedKResizing(nums1, 0) << endl;
    // 10

    vector<int> nums2 = {10, 20, 30};
    cout << Solution().minSpaceWastedKResizing(nums2, 1) << endl;
    // 10

    vector<int> nums3 = {10, 20, 15, 30, 20};
    cout << Solution().minSpaceWastedKResizing(nums3, 2) << endl;
    // 15

    return 0;
}
