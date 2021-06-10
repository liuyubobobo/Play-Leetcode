/// Source : https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/
/// Author : liuyubobobo
/// Time   : 2021-06-10

#include <iostream>
#include <vector>

using namespace std;


/// State Compression Memory Search
/// Time Complexity: O(n * 2^n)
/// Space Complexity: O(2^n)
class Solution {

private:
    int n;

public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {

        n = nums1.size();

        vector<int> dp(1 << n, -1);
        return dfs(nums1, nums2, 0, dp);
    }

private:
    int dfs(const vector<int>& nums1, const vector<int>& nums2, int state,
            vector<int>& dp){

        int index = __builtin_popcount(state);

        if(index == n) return 0;
        if(dp[state] != -1) return dp[state];

        int res = INT_MAX;
        for(int i = 0; i < n; i ++)
            if(!(state & (1 << i)))
                res = min(res, (nums1[index]^nums2[i]) + dfs(nums1, nums2, state | (1 << i), dp));
        return dp[state] = res;
    }
};


int main() {

    vector<int> nums11 = {1, 2, 3}, nums12 = {3, 2, 1};
    cout << Solution().minimumXORSum(nums11, nums12) << endl;
    // 0

    vector<int> nums21 = {1, 0, 3}, nums22 = {5, 3, 4};
    cout << Solution().minimumXORSum(nums21, nums22) << endl;
    // 8

    vector<int> nums31 = {72, 97, 8, 32, 15}, nums32 = {63, 97, 57, 60, 83};
    cout << Solution().minimumXORSum(nums31, nums32) << endl;
    // 152

    return 0;
}
