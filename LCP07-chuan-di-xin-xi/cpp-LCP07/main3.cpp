/// Source : https://leetcode-cn.com/problems/chuan-di-xin-xi/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>
#include <set>

using namespace  std;


/// Dynamic Preogramming
/// Time Complexity: O(k*(n + |relation|))
/// Space Complexity: O(n + |relation|)
class Solution {

public:
    int numWays(int n, vector<vector<int>>& relation, int k) {

        vector<set<int>> g(n);
        for(const vector<int>& arc: relation)
            g[arc[0]].insert(arc[1]);

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for(int i = 0; i < n; i ++)
            if(g[i].count(n - 1)) dp[i][1] = 1;

        for(int j = 2; j <= k; j ++)
            for(int i = 0; i < n; i ++)
                for(int next: g[i])
                    dp[i][j] += dp[next][j - 1];
        return dp[0][k];
    }
};


int main() {

    return 0;
}
