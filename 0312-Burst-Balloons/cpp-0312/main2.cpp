/// Source : https://leetcode.com/problems/burst-balloons/
/// Author : liuyubobobo
/// Time   : 2020-05-08

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int len = 2; len < n; len ++)
            for(int start = 0; start + len < n; start ++)
                for(int k = start + 1; k < start + len; k ++)
                    dp[start][start + len] = max(dp[start][start + len],
                                                 dp[start][k] + dp[k][start + len] + nums[start] * nums[k] * nums[start + len]);
        return dp[0][n - 1];
    }
};


int main() {

    vector<int> nums = {3,1,5,8};
    cout << Solution().maxCoins(nums) << endl;
    // 167

    return 0;
}
