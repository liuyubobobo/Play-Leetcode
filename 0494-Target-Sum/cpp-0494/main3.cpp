/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Memory Search
/// Using 2D-Array
///
/// Time Complexity: O(n * maxNum)
/// Space Complexity: O(n * maxNum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return dfs(nums, 0, S, dp);
    }

private:
    int dfs(const vector<int>& nums, int index, int S,
            vector<vector<int>>& dp){

        if(index == nums.size())
            return S == 0;

        if(S + 1000 < 0 || S + 1000 >= 2001)
            return 0;

        if(dp[index][S + 1000] != -1)
            return dp[index][S + 1000];

        int ret = 0;
        ret += dfs(nums, index + 1, S - nums[index], dp);
        ret += dfs(nums, index + 1, S + nums[index], dp);
        return dp[index][S + 1000] = ret;
    }
};


int main() {

    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;

    return 0;
}