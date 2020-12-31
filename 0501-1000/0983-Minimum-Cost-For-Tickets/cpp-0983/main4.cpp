/// Source : https://leetcode.com/problems/minimum-cost-for-tickets/
/// Author : liuyubobobo
/// Time   : 2019-01-28

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/// Memory Search
/// No need have 365 states, n states would be enough :-)
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

            int i1 = 0;
            for(; i1 < n; i1 ++)
                if(days[i1] >= days[i] + 7) break;
            dp[i] = min(dp[i], costs[1] + dp[i1]);

            int i2 = 0;
            for(; i2 < n; i2 ++)
                if(days[i2] >= days[i] + 30) break;
            dp[i] = min(dp[i], costs[2] + dp[i2]);
        }

        return dp[0];
    }
};


int main() {

    return 0;
}