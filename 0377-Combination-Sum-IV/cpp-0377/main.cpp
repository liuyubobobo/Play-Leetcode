/// Source : https://leetcode.com/problems/combination-sum-iv/description/
/// Author : liuyubobobo
/// Time   : 2018-03-04

#include <iostream>
#include <vector>

using namespace std;

/// Memory Search
/// Time Complexity: O(n * target)
/// Space Complexity: O(n * target)
class Solution {

private:
    vector<int> memo;

public:
    int combinationSum4(vector<int>& nums, int target) {

        if(nums.size() == 0)
            return 0;

        memo = vector<int>(target + 1, -1);
        solve(nums, target);

        return memo[target];
    }

private:
    int solve(const vector<int>& nums, int target){

        if(target == 0)
            return 1;

        if(memo[target] != -1)
            return memo[target];

        int res = 0;
        for(int i = 0; i < nums.size() ; i ++)
            if(target >= nums[i])
                res += solve(nums, target - nums[i]);

        return memo[target] = res;
    }
};

int main() {

    vector<int> nums1 = {1, 2, 3};
    int target1 = 4;
    cout << Solution().combinationSum4(nums1, target1) << endl;

    return 0;
}