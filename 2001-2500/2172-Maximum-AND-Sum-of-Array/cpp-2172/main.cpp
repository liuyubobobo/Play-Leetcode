/// Source : https://leetcode.com/problems/maximum-and-sum-of-array/
/// Author : liuyubobobo
/// Time   : 2022-02-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// State Compression DP
/// Time Complexity: O(n * 3^|numSlots| * numSlots)
/// Space Complexity: O(n * 3^|numSlots|)
class Solution {

public:
    int maximumANDSum(vector<int>& nums, int numSlots) {

        int n = nums.size();
        vector<int> slots(numSlots, 2);

        vector<vector<int>> dp(n, vector<int>(get_state(slots) + 1, INT_MIN));
        return dfs(n, nums, 0, slots, dp);
    }

private:
    int dfs(int n, const vector<int>& nums, int index, vector<int>& slots,
            vector<vector<int>>& dp){

        if(index == n) return 0;

        int slots_state = get_state(slots);

        if(dp[index][slots_state] != INT_MIN)
            return dp[index][slots_state];

        int res = INT_MIN;
        for(int i = 0; i < slots.size(); i ++)
            if(slots[i]){
                slots[i] --;
                res = max(res, (nums[index] & (i + 1)) + dfs(n, nums, index + 1, slots, dp));
                slots[i] ++;
            }
        return dp[index][slots_state] = res;
    }

    int get_state(const vector<int>& v){

        int res = 0;
        for(int e: v) res = res * 3 + e;
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    cout << Solution().maximumANDSum(nums1, 3) << endl;
    // 9

    vector<int> nums2 = {1, 3, 10, 4, 7, 1};
    cout << Solution().maximumANDSum(nums2, 9) << endl;
    // 24

    return 0;
}
