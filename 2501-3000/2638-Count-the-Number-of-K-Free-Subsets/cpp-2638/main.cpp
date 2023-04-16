/// Source : https://leetcode.com/problems/count-the-number-of-k-free-subsets/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {

        int n = nums.size();
        vector<vector<long long>> dp(2, vector<long long>(n + 1, 0));
        dp[0][1] = dp[1][1] = 1;
        for(int len = 2; len <= n; len ++){
            dp[0][len] = dp[0][len - 1] + dp[1][len - 1];
            dp[1][len] = dp[0][len - 1];
        }

        sort(nums.begin(), nums.end());

        long long res = 1;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i ++){
            if(visited[i]) continue;

            int chain_len = get_chain_len(nums, i, k, visited);
            res *= (dp[0][chain_len] + dp[1][chain_len]);
        }
        return res;
    }

private:
    int get_chain_len(const vector<int>& nums, int s, int k, vector<bool>& visited){

        int cur = nums[s], res = 1;
        while(true){
            auto iter = lower_bound(nums.begin(), nums.end(), cur + k);
            if(iter != nums.end() && *iter == cur + k){
                int index = iter - nums.begin();
                visited[index] = true;
                cur = nums[index];
                res ++;
            }
            else break;
        }
        return res;
    }
};


int main() {

    return 0;
}
