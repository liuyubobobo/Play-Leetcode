/// Source : https://leetcode.com/problems/number-of-great-partitions/description/
/// Author : liuyubobobo
/// Time   : 2022-12-28

#include <iostream>
#include <vector>

using namespace std;


/// Knapback
/// Time Complexity: O(nk)
/// Space Complexity: O(nk)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countPartitions(vector<int>& nums, int k) {

        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(k, 0));

        dp[0][0] = 1;
        for(int i = 0; i < n; i ++){
            for(int C = 0; C < k; C ++){
                dp[i + 1][C] = dp[i][C];
                if(C - nums[i] >= 0)
                    dp[i + 1][C] += dp[i][C - nums[i]],
                    dp[i + 1][C] %= MOD;
            }
        }

        long long sum = 0;
        for(int e: nums) sum += e;

        long long t = 0;
        for(int C = 0; C < k; C ++){
            t += dp[n][C];
            if(sum - C >= k) t += dp[n][C];
            t %= MOD;
        }
//        cout << t << '\n';

        long long res = 1;
        for(int i = 0; i < n; i ++) res = res * 2 % MOD;

        res = (res - t + MOD) % MOD;
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4};
    cout << Solution().countPartitions(nums1, 4) << '\n';
    // 6

    vector<int> nums2 = {3, 3, 3};
    cout << Solution().countPartitions(nums2, 4) << '\n';
    // 0

    vector<int> nums3 = {6, 6};
    cout << Solution().countPartitions(nums3, 2) << '\n';
    // 2

    vector<int> nums4 = {96,40,22,98,9,97,45,22,79,57,95,62};
    cout << Solution().countPartitions(nums4, 505) << '\n';
    // 0

    return 0;
}
