/// Source : https://leetcode.com/problems/greatest-sum-divisible-by-three/
/// Author : liuyubobobo
/// Time   : 2020-02-17

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(3n)
/// Space Complexity: O(3n)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        vector<vector<int>> dp(nums.size(), vector<int>(3, -1));
        return dfs(nums, 0, 0, dp);
    }

private:
    int dfs(const vector<int>& nums, int index, int mod, vector<vector<int>>& dp){

        if(index == nums.size()) return mod == 0 ? 0 : -1;
        if(dp[index][mod] != -1) return dp[index][mod];

        int res = dfs(nums, index + 1, mod, dp);
        int t = dfs(nums, index + 1, (mod - nums[index] % 3 + 3) % 3, dp);
        if(t >= 0) res = max(res, nums[index] + t);
        return dp[index][mod] = res;
    }
};


int main() {

    vector<int> nums1 = {3,6,5,1,8};
    cout << Solution().maxSumDivThree(nums1) << endl;
    // 18

    vector<int> nums2 = {1,2,3,4,4};
    cout << Solution().maxSumDivThree(nums2) << endl;
    // 12

    vector<int> nums3 = {2,3,36,8,32,38,3,30,13,40};
    cout << Solution().maxSumDivThree(nums3) << endl;
    // 195

    return 0;
}
