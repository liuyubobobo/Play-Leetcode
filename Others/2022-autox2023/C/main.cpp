/// Source : https://leetcode.cn/contest/autox2023/problems/BjAFy9/
/// Author : liuyubobobo
/// Time   : 2022-08-28

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


/// DP + Binary Search
/// Time Complexity: O(|days| * |tickets| * log|days|)
/// Space Complexity: O(|days|)
class Solution {
public:
    long long minCostToTravelOnDays(vector<int>& days, vector<vector<int>>& tickets) {

        int n = days.size();
        vector<long long> dp(n, LONG_LONG_MAX);
        for(int i = n - 1; i >= 0; i --){
            long long cur = LONG_LONG_MAX;
            for(const vector<int>& ticket: tickets){
                long long price = ticket[1];
                int d = ticket[0];
                auto iter = lower_bound(days.begin() + i, days.end(), days[i] + d);

                if(iter == days.end()) cur = min(cur, price);
                else cur = min(cur, price + dp[iter - days.begin()]);
            }
            dp[i] = cur;
        }
        return dp[0];
    }
};


int main() {

    return 0;
}
