/// Source : https://leetcode.com/problems/constrained-subset-sum/
/// Author : liuyubobobo
/// Time   : 2020-04-27

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// DP + Using Deque to Optimize
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        int max_value = *max_element(nums.begin(), nums.end());
        if(max_value <= 0) return max_value;

        int n = nums.size(), res = 0;
        vector<int> dp(n);
        deque<int> q;
        for(int i = 0; i < n; i ++){
            dp[i] = nums[i];
            if(q.size())
                dp[i] = max(dp[i], nums[i] + q.front());
            res = max(res, dp[i]);

            while(!q.empty() && q.back() < dp[i])
                q.pop_back();
            q.push_back(dp[i]);

            if(i >= k && q.front() == dp[i - k])
                q.pop_front();
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
