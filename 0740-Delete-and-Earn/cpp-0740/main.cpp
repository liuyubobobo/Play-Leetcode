#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
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

        vector<int> dp(maxNum + 1, -1);

        return findResult(scores, 0, maxNum, dp);
    }

private:
    int findResult(const vector<int>& scores,
                   int index, int lastIndex, vector<int>& dp){

        if(index > lastIndex)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        if(index == lastIndex)
            return dp[index] = scores[index];

        return dp[index] = max(findResult(scores, index + 1, lastIndex, dp),
                               scores[index] + findResult(scores, index + 2, lastIndex, dp));
    }
};

int main() {

    vector<int> nums1 = {3, 4, 2};
    cout << Solution().deleteAndEarn(nums1) << endl;

    vector<int> nums2 = {2, 2, 3, 3, 3, 4};
    cout << Solution().deleteAndEarn(nums2) << endl;

    return 0;
}