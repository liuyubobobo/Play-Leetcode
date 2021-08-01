#include <iostream>
#include <vector>

using namespace std;


class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countSpecialSubsequences(vector<int>& nums) {

        int n = nums.size();
        vector<vector<long long>> dp(4, vector<long long>(n, -1ll));
        return dfs(nums, 0, 0, dp, n);
    }

private:
    long long dfs(vector<int>& nums, int index, int v, vector<vector<long long>>& dp, int n){

        if(v == 3) return 1ll;
        if(index == n) return 0ll;
        if(dp[v][index] != -1ll) return dp[v][index];

        long long res = 0ll;
        if(nums[index] == v){
            res = dfs(nums, index + 1, v + 1, dp, n);
            res += dfs(nums, index + 1, v, dp, n);
            res %= MOD;
        }
        else{
            res += dfs(nums, index + 1, v, dp, n);
//            res %= MOD;
        }
        return dp[v][index] = res;
    }
};

int main() {

    vector<int> nums1 = {0, 1, 2, 2};
    cout << Solution().countSpecialSubsequences(nums1) << endl;
    // 3

    return 0;
}
