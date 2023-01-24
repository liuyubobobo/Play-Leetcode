/// Source : https://leetcode.com/problems/minimum-cost-to-split-an-array/description/
/// Author : liuyubobobo
/// Time   : 2023-01-22

#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int minCost(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> f(n, 0);

        vector<int> dp(n + 1, INT_MAX / 2);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i --){
            f.assign(n, 0);
            int trim_value = 0;
            for(int j = i; j >= 0; j --){
                f[nums[j]] ++;
                int len = f[nums[j]];
                if(len == 2) trim_value += 2;
                else if(len > 2) trim_value ++;
                dp[j] = min(dp[j], trim_value + k + dp[i + 1]);
            }
        }
        return dp[0];
    }
};


int main() {

    return 0;
}
