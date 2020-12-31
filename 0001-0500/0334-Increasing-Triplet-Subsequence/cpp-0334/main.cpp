/// Source : https://leetcode.com/problems/increasing-triplet-subsequence/
/// Author : liuyubobobo
/// Time   : 2020-12-18

#include <iostream>
#include <vector>

using namespace std;


/// LIS
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        vector<int> dp = {nums[0]};
        for(int i = 1; i < nums.size(); i ++){
            vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(iter == dp.end())
                dp.push_back(nums[i]);
            else
                dp[iter - dp.begin()] = nums[i];

        }
        return dp.size() >= 3;
    }
};


int main() {

    return 0;
}
