/// Source : https://leetcode.com/problems/largest-divisible-subset/
/// Author : liuyubobobo
/// Time   : 2021-04-23

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 1), pre(nums.size(), -1);
        for(int i = 1; i < nums.size(); i ++)
            for(int j = i - 1; j >= 0; j --)
                if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
                    dp[i] = 1 + dp[j], pre[i] = j;

        int cur = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> res;
        while(cur != -1){
            res.push_back(nums[cur]);
            cur = pre[cur];
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {1, 2, 3};
    print_vec(Solution().largestDivisibleSubset(nums1));
    // 1 2

    vector<int> nums2 = {3, 4, 16, 8};
    print_vec(Solution().largestDivisibleSubset(nums2));
    // 4 8 16

    vector<int> nums3 = {2000000000};
    print_vec(Solution().largestDivisibleSubset(nums3));
    // 2000000000

    vector<int> nums4 = {1, 2, 3};
    print_vec(Solution().largestDivisibleSubset(nums4));
    // 1 2

    return 0;
}
