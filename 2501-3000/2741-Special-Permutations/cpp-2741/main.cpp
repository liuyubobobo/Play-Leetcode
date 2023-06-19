/// Source : https://leetcode.com/problems/special-permutations/description/
/// Author : liuyubobobo
/// Time   : 2023-06-18

#include <iostream>
#include <vector>

using namespace std;


/// Bitmask + Memoization
/// Time Complexity: O(n^2 * 2^n)
/// Space Complexity: O(n * 2^n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int specialPerm(vector<int>& nums) {

        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(1 << n, -1));
        return dfs(nums, 0, (1 << n) - 1, dp);
    }

private:
    long long dfs(const vector<int>& nums, int last_index, int state, vector<vector<long long>>& dp) {

        if(state == 0) return 1;
        if(dp[last_index][state] != -1) return dp[last_index][state];

        long long res = 0;
        for(int i = 0; i < nums.size(); i ++) {
            if((state & (1 << i)) == 0) continue;
            if(last_index == 0) res += dfs(nums, i + 1, state ^ (1 << i), dp);
            else if(nums[i] % nums[last_index - 1] == 0 || nums[last_index - 1] % nums[i] == 0)
                res += dfs(nums, i + 1, state ^ (1 << i), dp);
        }
        return dp[last_index][state] = res % MOD;
    }
};


int main() {

    return 0;
}
