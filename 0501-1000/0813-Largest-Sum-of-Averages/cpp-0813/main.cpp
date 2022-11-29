/// Source : https://leetcode.com/problems/largest-sum-of-averages/
/// Author : liuyubobobo
/// Time   : 2022-11-27

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Compleixty: O(n^2 * k)
/// Space Complexity: O(nk)
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {

        int n = nums.size();
        vector<vector<double>> dp(k + 1, vector<double>(n, 0.0));

        int sum = 0;
        for(int i = n - 1; i >= 0; i --){
            sum += nums[i];
            dp[1][i] = (double)sum / (n - i);
        }

        for(int seg = 2; seg <= k; seg ++){
            for(int l = 0; n - l >= seg; l ++){
                int sum = 0;
                for(int r = l; n - r >= seg; r ++){
                    sum += nums[r];
                    dp[seg][l] = max(dp[seg][l], (double)sum / (r - l + 1) + dp[seg - 1][r + 1]);
                }
            }
        }

        double res = dp[1][0];
        for(int seg = 2; seg <= k; seg ++) res = max(res, dp[seg][0]);
        return res;
    }
};


int main() {

    vector<int> nums1 = {9,1,2,3,9};
    cout << Solution().largestSumOfAverages(nums1, 3) << '\n';
    // 20

    return 0;
}
