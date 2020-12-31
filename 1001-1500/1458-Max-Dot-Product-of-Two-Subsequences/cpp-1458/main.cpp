/// Source : https://leetcode.com/problems/max-dot-product-of-two-subsequences/
/// Author : liuyubobobo
/// Time   : 2020-05-23

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n1 * n2)
/// Space Complexity: O(n1 * n2)
class Solution {

public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), INT_MIN));
        int res = dfs(nums1, nums2, 0, 0, dp);
        return res;
    }

private:
    int dfs(const vector<int>& nums1, const vector<int>& nums2, int index1, int index2,
            vector<vector<int>>& dp){

        if(index1 == nums1.size() || index2 == nums2.size()) return -1e9;
        if(dp[index1][index2] != INT_MIN) return dp[index1][index2];

        int res = nums1[index1] * nums2[index2];
        res = max(res, nums1[index1] * nums2[index2] + dfs(nums1, nums2, index1 + 1, index2 + 1, dp));
        res = max(res, dfs(nums1, nums2, index1 + 1, index2, dp));
        res = max(res, dfs(nums1, nums2, index1, index2 + 1, dp));
        res = max(res, dfs(nums1, nums2, index1 + 1, index2 + 1, dp));

        return dp[index1][index2] = res;
    }
};


int main() {

    vector<int> nums11 = {2,1,-2,5}, nums21 = {3,0,-6};
    cout << Solution().maxDotProduct(nums11, nums21) << endl;
    // 18

    vector<int> nums12 = {3, -2}, nums22 = {2, -6, 7};
    cout << Solution().maxDotProduct(nums12, nums22) << endl;
    // 21

    vector<int> nums13 = {-1, -1}, nums23 = {1, 1};
    cout << Solution().maxDotProduct(nums13, nums23) << endl;
    // -1

    vector<int> nums14 = {-5, -1, -2}, nums24 = {3, 3, 5, 5};
    cout << Solution().maxDotProduct(nums14, nums24) << endl;
    // -3

    vector<int> nums15 = {-5, -1, -2}, nums25 = {3, 5};
    cout << Solution().maxDotProduct(nums15, nums25) << endl;
    // -3

    vector<int> nums16 = {5, -4, -3}, nums26 = {-4, -3, 0, -4, 2};
    cout << Solution().maxDotProduct(nums16, nums26) << endl;
    // 28

    return 0;
}
