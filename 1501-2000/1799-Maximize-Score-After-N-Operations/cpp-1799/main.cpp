/// Source : https://leetcode.com/problems/maximize-score-after-n-operations/
/// Author : liuyubobobo
/// Time   : 2021-03-21

#include <iostream>
#include <vector>

using namespace std;


/// State Compression Memory Search
/// Time Complexity: O(n^3 * (2^n))
/// Space Complexity: O(n * 2^n)
class Solution {

private:
    int n;

public:
    int maxScore(vector<int>& nums) {

        n = nums.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        for(int i = 0; i < nums.size(); i ++)
            for(int j = i + 1; j < nums.size(); j ++)
                table[i][j] = table[j][i] = gcd(nums[i], nums[j]);

        vector<vector<int>> dp(n / 2, vector<int>(1 << n, -1));
        return dfs(nums, 0, 0, dp, table);
    }

private:
    int dfs(const vector<int>& nums, int op, int state, vector<vector<int>>& dp,
            const vector<vector<int>>& table){

        if(op == dp.size()) return 0;
        if(dp[op][state] != -1) return dp[op][state];

        int res = 0;
        for(int i = 0; i < n; i ++)
            if((state & (1 << i)) == 0)
                for(int j = i + 1; j < n; j ++)
                    if((state & (1 << j)) == 0)
                        res = max(res, table[i][j] * (op + 1) + dfs(nums, op + 1, state + (1 << i) + (1 << j), dp, table));
        return dp[op][state] = res;
    }

    int gcd(int x, int y){

        if(x > y) swap(x, y);

        if(y % x == 0) return x;
        return gcd(y % x, x);
    }
};


int main() {

    vector<int> nums1 = {1, 2};
    cout << Solution().maxScore(nums1) << endl;
    // 1

    vector<int> nums2 = {3, 4, 6, 8};
    cout << Solution().maxScore(nums2) << endl;
    // 11

    vector<int> nums3 = {1, 2, 3, 4, 5, 6};
    cout << Solution().maxScore(nums3) << endl;
    // 14

    return 0;
}
