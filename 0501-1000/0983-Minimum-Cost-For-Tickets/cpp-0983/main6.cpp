/// Source : https://leetcode.com/problems/minimum-cost-for-tickets/
/// Author : liuyubobobo
/// Time   : 2019-01-28

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/// Dynamic Programming
/// No need have 365 states, n states would be enough :-)
/// Since days is in increasing order, we can use binary search to get next state more quickly :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(len(days))
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();
        vector<int> dp(n + 1, 0);
        dp[n - 1] = costs[0];
        for(int i = n - 2; i >= 0; i --){
            dp[i] = costs[0] + dp[i + 1];

            int i1 = upper_bound(days.begin(), days.end(), days[i] + 6) - days.begin();
            dp[i] = min(dp[i], costs[1] + dp[i1]);

            int i2 = upper_bound(days.begin(), days.end(), days[i] + 29) - days.begin();
            dp[i] = min(dp[i], costs[2] + dp[i2]);
        }

        return dp[0];
    }
};


int main() {

    return 0;
}