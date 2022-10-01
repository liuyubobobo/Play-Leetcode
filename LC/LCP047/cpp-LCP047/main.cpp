/// Source : https://leetcode-cn.com/problems/oPs9Bm/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>
#include <numeric>

using namespace  std;


/// Memoization
/// Time Complexity: O(n * k)
/// Space Complexity: O(n * k)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int securityCheck(vector<int>& capacities, int k) {

        int n = capacities.size();
        int sum = accumulate(capacities.begin(), capacities.end(), 0);

        // 0 - queue, 1 - stack
        // room, k-th to go out
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(sum + 1, -1)));
        int res = dfs(capacities, k, sum, 0, n - 1, 0, dp);
        res += dfs(capacities, k, sum, 1, n - 1, 0, dp);
        return res % MOD;
    }

private:
    int dfs(const vector<int>& capacities, const int k, const int sum,
            int is_stack, int index, int go_out,
            vector<vector<vector<int>>>& dp){

        if(index == -1){
            if(is_stack) return k == capacities[0] - 1 + go_out;
            return k == go_out;
        }
        assert(go_out <= sum);
        if(dp[is_stack][index][go_out] != -1) return dp[is_stack][index][go_out];

        int res = 0;
        if(is_stack){
            res += dfs(capacities, k, sum, 1, index - 1, capacities[index] - 1 + go_out, dp);
            res += dfs(capacities, k, sum, 0, index - 1, capacities[index] - 1 + go_out, dp);
            res %= MOD;
        }
        else{
            res += dfs(capacities, k, sum, 1, index - 1, go_out, dp);
            res += dfs(capacities, k, sum, 0, index - 1, go_out, dp);
            res %= MOD;
        }
        return dp[is_stack][index][go_out] = res;
    }
};


int main() {

    vector<int> cap1 = {2, 2, 3};
    cout << Solution().securityCheck(cap1, 2) << endl;
    // 2

    vector<int> cap2 = {3, 3};
    cout << Solution().securityCheck(cap2, 3) << endl;
    // 0

    vector<int> cap3 = {4, 3, 2, 2};
    cout << Solution().securityCheck(cap3, 6) << endl;
    // 2

    return 0;
}
