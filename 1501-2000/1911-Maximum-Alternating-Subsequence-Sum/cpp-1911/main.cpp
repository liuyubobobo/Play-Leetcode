/// Source : https://leetcode.com/problems/maximum-alternating-subsequence-sum/
/// Author : liuyubobobo
/// Time   : 2021-06-2

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int n;

public:
    long long maxAlternatingSum(vector<int>& nums) {

        n = nums.size();
        vector<vector<long long>> dp(2, vector<long long>(n, LONG_LONG_MIN));
        return solve(nums, 0, 0, dp);
    }

private:
    long long solve(const vector<int>& nums, int index, int odd,
                    vector<vector<long long>>& dp){

        if(index == n) return 0;
        if(dp[odd][index] != LONG_LONG_MIN) return dp[odd][index];

        long long res = solve(nums, index + 1, odd, dp);
        if(odd)
            res = max(res, -nums[index] + solve(nums, index + 1, !odd, dp));
        else
            res = max(res, nums[index] + solve(nums, index + 1, !odd, dp));
        return dp[odd][index] = res;
    }
};


int main() {

    return 0;
}
