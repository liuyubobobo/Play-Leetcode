/// Source : https://leetcode.com/problems/maximum-strength-of-a-group/
/// Author : liuyubobobo
/// Time   : 2023-05-27

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    long long maxStrength(vector<int>& nums) {

        int n = nums.size();

        vector<long long> dp(1 << n, 1);
        for(int state = 1; state < (1 << n); state ++){
            int p = __builtin_ffs(state) - 1;
            dp[state] = dp[state ^ (1 << p)] * nums[p];
        }
        return *max_element(dp.begin() + 1, dp.end());
    }
};


int main() {

    return 0;
}
