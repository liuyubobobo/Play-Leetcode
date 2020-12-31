/// Source : https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
/// Author : liuyubobobo
/// Time   : 2020-09-05

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minCost(string s, vector<int>& cost) {

        vector<vector<int>> dp(27, vector<int>(s.size(), -1));
        return dfs(s, cost, 26, 0, dp);
    }

private:
    int dfs(const string& s, const vector<int>& cost, int pre, int index,
            vector<vector<int>>& dp){

        if(index == s.size()) return 0;
        if(dp[pre][index] != -1) return dp[pre][index];

        int res = cost[index] + dfs(s, cost, pre, index + 1, dp);
        if(pre != s[index] - 'a')
            res = min(res, dfs(s, cost, s[index] - 'a', index + 1, dp));
        return dp[pre][index] = res;
    }
};


int main() {

    vector<int> cost1 = {1,2,3,4,5};
    cout << Solution().minCost("abaac", cost1) << endl;
    // 3

    vector<int> cost2 = {1,2,3};
    cout << Solution().minCost("abc", cost2) << endl;
    // 0

    vector<int> cost3 = {1,2,3, 4, 1};
    cout << Solution().minCost("aabaa", cost3) << endl;
    // 2

    return 0;
}
