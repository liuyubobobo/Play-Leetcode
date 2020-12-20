/// Source : https://leetcode.com/problems/jump-game-vi/
/// Author : liuyubobobo
/// Time   : 2020-12-19

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Tree Map
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> dp(n, nums[0]);

        map<int, int> tree;
        tree[nums[0]] ++;

        for(int i = 1; i < nums.size(); i ++){

            dp[i] = nums[i] + tree.rbegin()->first;
            tree[dp[i]] ++;

            if(i >= k){
                tree[dp[i - k]] --;
                if(tree[dp[i - k]] == 0) tree.erase(dp[i - k]);
            }
        }
        return dp.back();
    }
};


int main() {

    vector<int> nums1 = {1,-1,-2,4,-7,3};
    cout << Solution().maxResult(nums1, 2) << endl;
    // 7

    vector<int> nums2 = {10,-5,-2,4,0,3};
    cout << Solution().maxResult(nums2, 3) << endl;
    // 17

    vector<int> nums3 = {1,-5,-20,4,-1,3,-6,-3};
    cout << Solution().maxResult(nums3, 2) << endl;
    // 0

    return 0;
}
