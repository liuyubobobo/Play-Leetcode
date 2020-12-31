/// Source : https://leetcode.com/problems/minimum-cost-for-tickets/
/// Author : liuyubobobo
/// Time   : 2019-01-28

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;


/// Dynamic Programming - Day Variant
/// Time Complexity: O(365)
/// Space Complexity: O(len(days))
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        unordered_set<int> day_set;
        for(int day: days)
            day_set.insert(day);

        vector<int> dp(400, 0);
        dp[365] = day_set.count(365) ? costs[0] : 0;
        for(int day = 364; day >= 1; day --) {
            if (!day_set.count(day)) dp[day] = dp[day + 1];
            else{
                dp[day] = costs[0] + dp[day + 1];
                dp[day] = min(dp[day], costs[1] + dp[day + 7]);
                dp[day] = min(dp[day], costs[2] + dp[day + 30]);
            }
        }
        return dp[1];
    }
};


int main() {

    return 0;
}