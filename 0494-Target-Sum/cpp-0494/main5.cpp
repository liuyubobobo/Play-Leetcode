/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Dynamic Programming
/// Using 1D Array
///
/// Time Complexity: O(n * maxNum)
/// Space Complexity: O(maxNum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        vector<int> dp(2001, 0);
        dp[1000 - nums[0]] += 1;
        dp[1000 + nums[0]] += 1;
        for(int i = 1; i < nums.size(); i ++){
            vector<int> a(2001, 0);
            for(int j = 0; j < 2001; j ++){
                if(j - nums[i] >= 0 && j - nums[i] < 2001)
                    a[j] += dp[j - nums[i]];
                if(j + nums[i] >= 0 && j + nums[i] < 2001)
                    a[j] += dp[j + nums[i]];
            }
            dp = a;
        }

        if(1000 + S < 0 || 1000 + S >= 2001)
            return 0;
        return dp[1000 + S];
    }
};


int main() {

    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;

    return 0;
}