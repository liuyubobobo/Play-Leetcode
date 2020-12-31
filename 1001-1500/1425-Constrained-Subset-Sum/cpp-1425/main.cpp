/// Source : https://leetcode.com/problems/constrained-subset-sum/
/// Author : liuyubobobo
/// Time   : 2020-04-27

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DP + Using Map as a Priority Queue to Optimize
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        int max_value = *max_element(nums.begin(), nums.end());
        if(max_value <= 0) return max_value;

        int n = nums.size(), res = 0;
        vector<int> dp(n);
        map<int, int> tree;
        for(int l = 0, r = 0; r < n; r ++){
            dp[r] = nums[r];
            if(tree.size())
                dp[r] = max(dp[r], nums[r] + tree.rbegin()->first);
            res = max(res, dp[r]);

            tree[dp[r]] ++;
            if(r - l >= k){
                tree[dp[l]] --;
                if(tree[dp[l]] == 0) tree.erase(dp[l]);
                l ++;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {10,2,-10,5,20};
    cout << Solution().constrainedSubsetSum(nums1, 2) << endl;
    // 37

    vector<int> nums2 = {-1, -2, -3};
    cout << Solution().constrainedSubsetSum(nums2, 1) << endl;
    // -1

    vector<int> nums3 = {10,-2,-10,-5,20};
    cout << Solution().constrainedSubsetSum(nums3, 2) << endl;
    // 23

    vector<int> nums4 = {-8269,3217,-4023,-4138,-683,6455,-3621,9242,4015,-3790};
    cout << Solution().constrainedSubsetSum(nums4, 1) << endl;
    // 16091

    return 0;
}
