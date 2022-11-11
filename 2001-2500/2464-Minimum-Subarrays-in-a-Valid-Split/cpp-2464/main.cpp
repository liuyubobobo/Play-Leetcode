/// Source : https://leetcode.com/problems/minimum-subarrays-in-a-valid-split/description/
/// Author : liuyubobobo
/// Time   : 2022-11-10

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n^2 * log(max_num))
/// Space Complexity: O(n)
class Solution {
public:
    int validSubarraySplit(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n + 1, INT_MAX / 2);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i --){
            for(int j = i; j < n; j ++)
                if(gcd(nums[i], nums[j]) > 1)
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
        }
        return dp[0] >= INT_MAX / 2 ? -1 : dp[0];
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
