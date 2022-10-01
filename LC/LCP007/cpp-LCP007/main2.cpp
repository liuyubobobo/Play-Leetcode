/// Source : https://leetcode-cn.com/problems/chuan-di-xin-xi/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>
#include <set>

using namespace  std;


/// Memory Search
/// Time Complexity: O(n*n*k)
/// Space Complexity: O(n*k)
class Solution {

public:
    int numWays(int n, vector<vector<int>>& relation, int k) {

        vector<set<int>> g(n);
        for(const vector<int>& arc: relation)
            g[arc[0]].insert(arc[1]);

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return dfs(g, 0, n - 1, k, dp);
    }

private:
    int dfs(const vector<set<int>>& g, int start, int end, int step,
            vector<vector<int>>& dp){

        if(step == 0) return start == end;
        if(dp[start][step] != -1) return dp[start][step];

        int res = 0;
        for(int next: g[start])
            res += dfs(g, next, end, step - 1, dp);
        return dp[start][step] = res;
    }
};


int main() {

    return 0;
}
