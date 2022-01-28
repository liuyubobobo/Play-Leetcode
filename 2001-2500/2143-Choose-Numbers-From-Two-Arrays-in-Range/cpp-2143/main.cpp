/// Source : https://leetcode.com/problems/choose-numbers-from-two-arrays-in-range/
/// Author : liuyubobobo
/// Time   : 2022-01-28

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Memoization
/// Time Complexity: O(n * (sum1 + sum2))
/// Space Complexity: O(n * (sum1 + sum2))
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int countSubranges(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        vector<vector<int>> dp(n, vector<int>(sum1 + sum2 + 1, -1)); // index, sum -> cnt

        int res = 0;
        for(int i = 0; i < n; i ++)
            res += dfs(n, nums1, nums2, i, 0, dp, sum2), res %= MOD;
        return res;
    }

private:
    int dfs(int n, const vector<int>& nums1, const vector<int>& nums2, int index, int target,
            vector<vector<int>>& dp, int offset){

        if(index == n) return 0;
        if(dp[index][target + offset] != -1) return dp[index][target + offset];

        int res = 0;
        if(nums1[index] == target) res ++;
        if(nums2[index] == -target) res ++;
        res += dfs(n, nums1, nums2, index + 1, target - nums1[index], dp, offset);
        res += dfs(n, nums1, nums2, index + 1, target + nums2[index], dp, offset);
        return dp[index][target + offset] = res % MOD;
    }
};


int main() {

    vector<int> nums11 = {1, 2, 5}, nums12 = {2, 6, 3};
    cout << Solution().countSubranges(nums11, nums12) << endl;
    // 3

    vector<int> nums21 = {0, 1}, nums22 = {1, 0};
    cout << Solution().countSubranges(nums21, nums22) << endl;
    // 4

    return 0;
}
