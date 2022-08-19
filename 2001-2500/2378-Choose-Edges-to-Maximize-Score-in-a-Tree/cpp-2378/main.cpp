/// Source : https://leetcode.com/problems/choose-edges-to-maximize-score-in-a-tree/
/// Author : liuyubobobo
/// Time   : 2022-08-19

#include <iostream>
#include <vector>
#include <list>
#include <numeric>

using namespace std;


/// Tree DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long maxScore(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<list<pair<int, long long>>> tree(n);

        for(int i = 1; i < n; i ++){
            int p = edges[i][0];
            long long w = edges[i][1];
            tree[p].push_back({i, w});
        }

        vector<vector<long long>> dp(2, vector<long long>(n, -1));
        return dfs(tree, 1, 0, dp);
    }

private:
    long long dfs(const vector<list<pair<int, long long>>>& tree,
                  int can_choose, int u, vector<vector<long long>>& dp){

        if(dp[can_choose][u] != -1) return dp[can_choose][u];

        long long sum = 0;
        for (const pair<int, long long> &p: tree[u])
            sum += dfs(tree, 1, p.first, dp);

        if(can_choose == 0) {
            return dp[can_choose][u] = sum;
        }

        long long res = sum;
        for(const pair<int, long long>& p: tree[u]){
            long long tres = sum;
            tres += p.second;
            tres -= dfs(tree, 1, p.first, dp);
            tres += dfs(tree, 0, p.first, dp);
            res = max(res, tres);
        }
        return dp[can_choose][u] = res;
    }
};


int main() {

    return 0;
}
