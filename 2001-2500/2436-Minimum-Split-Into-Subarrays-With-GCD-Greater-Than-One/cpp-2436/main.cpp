/// Source : https://leetcode.com/problems/minimum-split-into-subarrays-with-gcd-greater-than-one/
/// Author : liuyubobobo
/// Time   : 2022-10-12

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// DP
/// Time Complexity: O(n^2 * log(max(nums)))
/// Space Complexity: O(n)
class Solution {
public:
    int minimumSplits(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i --){
            dp[i] = 1 + dp[i + 1];
            int cur = nums[i];
            for(int j = i + 1; j < n && cur > 1; j ++){
                cur = gcd(cur,nums[j]);
                if(cur > 1) dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }
        return dp[0];
    }

private:
    int gcd(int a, int b){
        if(a > b) swap(a, b);
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    return 0;
}
