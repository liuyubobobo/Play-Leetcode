/// Source : https://leetcode.com/problems/minimum-cost-for-tickets/
/// Author : liuyubobobo
/// Time   : 2019-01-28

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;


/// Memory Search - Day Variant
/// Time Complexity: O(365)
/// Space Complexity: O(len(days))
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        unordered_set<int> day_set;
        for(int day: days)
            day_set.insert(day);

        vector<int> dp(366, -1);
        return dfs(0, day_set, costs, dp);
    }

private:
    int dfs(int day, const unordered_set<int> day_set, const vector<int>& costs,
            vector<int>& dp){

        if(day > 365) return 0;
        if(dp[day] != -1) return dp[day];

        if(!day_set.count(day))
            return dp[day] = dfs(day + 1, day_set, costs, dp);

        int res = costs[0] + dfs(day + 1, day_set, costs, dp);
        res = min(res, costs[1] + dfs(day + 7, day_set, costs, dp));
        res = min(res, costs[2] + dfs(day + 30, day_set, costs, dp));

        return dp[day] = res;
    }
};


int main() {

    return 0;
}