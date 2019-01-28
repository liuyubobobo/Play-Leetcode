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
        vector<int> dp(n, -1);

        return dfs(days, 0, n, costs, dp);
    }

private:
    int dfs(const vector<int>& days, int index, int n, const vector<int>& costs, vector<int>& dp){

        if(index >= n) return 0;
        if(dp[index] != -1) return dp[index];

        int res = costs[0] + dfs(days, index + 1, n, costs, dp);

        int i1 = 0;
        for(; i1 < n; i1 ++)
            if(days[i1] >= days[index] + 7) break;
        res = min(res, costs[1] + dfs(days, i1, n, costs, dp));

        int i2 = 0;
        for(; i2 < n; i2 ++)
            if(days[i2] >= days[index] + 30) break;
        res = min(res, costs[2] + dfs(days, i2, n, costs, dp));

        return dp[index] = res;
    }
};


int main() {

    return 0;
}