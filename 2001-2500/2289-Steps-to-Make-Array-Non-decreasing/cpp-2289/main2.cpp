/// Source : https://leetcode.com/problems/steps-to-make-array-non-decreasing/
/// Author : liuyubobobo
/// Time   : 2022-06-04

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int totalSteps(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 0);
        stack<int> s;
        for(int i = n - 1; i >= 0; i --){
            while(!s.empty() && nums[i] > nums[s.top()]){
                dp[i] ++;
                dp[i] = max(dp[i], dp[s.top()]);
                s.pop();
            }
            s.push(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<int> nums1 = {7, 14, 4, 14, 13, 2, 6, 13};
    cout << Solution().totalSteps(nums1) << '\n';
    // 3

    return 0;
}
