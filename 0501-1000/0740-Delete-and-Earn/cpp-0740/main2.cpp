#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
/// This problem can be transform into House Robber Problem
/// See: https://leetcode.com/problems/house-robber/description/
///
/// Time Complexity: O(maxNum)
/// Space Complexity: O(maxNum)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        vector<int> scores(10001, 0);
        int maxNum = 0;
        for(int num: nums){
            scores[num] += num;
            maxNum = max(num, maxNum);
        }

        vector<int> dp(maxNum + 1, 0);
        dp[1] = scores[1];
        for(int i = 2 ; i <= maxNum ; i ++)
            dp[i] = max(dp[i-1], scores[i] + dp[i-2]);
        return dp[maxNum];
    }
};

int main() {

    vector<int> nums1 = {3, 4, 2};
    cout << Solution().deleteAndEarn(nums1) << endl;

    vector<int> nums2 = {2, 2, 3, 3, 3, 4};
    cout << Solution().deleteAndEarn(nums2) << endl;

    return 0;
}