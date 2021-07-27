/// Source : https://leetcode.com/problems/jump-game-ii/
/// Author : liuyubobobo
/// Time   : 2021-05-05

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// TLE
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < n; i ++)
            for(int j = i - 1; j >= 0; j --)
                if(dp[j] != INT_MAX && j + nums[j] >= i)
                    dp[i] = min(dp[i], 1 + dp[j]);
        return dp.back();
    }
};


int main() {

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << Solution().jump(nums1) << endl;
    // 2

    return 0;
}
