/// Source : https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
/// Author : liuyubobobo
/// Time   : 2022-08-10

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool validPartition(vector<int>& nums) {

        int n = nums.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;
        dp[2] = (nums[1] == nums[0]);

        for(int i = 2; i < n; i ++){
            if(nums[i] == nums[i - 1] && dp[i - 2 + 1])
                dp[i + 1] = true;
            if(nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2] && dp[i - 3 + 1])
                dp[i + 1] = true;
            if(nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1 && dp[i - 3 + 1])
                dp[i + 1] = true;
        }
        return dp[n];
    }
};


int main() {

    return 0;
}
