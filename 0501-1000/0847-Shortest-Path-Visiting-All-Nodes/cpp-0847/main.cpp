/// Source : https://leetcode.com/problems/shortest-path-visiting-all-nodes/
/// Author : liuyubobobo
/// Time   : 2021-08-06

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Memoization
/// Time Complexity: O(n^2 + O(n * 2^n))
/// Space Complexity: O(n^2 + O(n * 2^n))
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {

        int n = g.size();
        vector<vector<int>> dis(n, vector<int>(n, 0));
        for(int s = 0; s < n; s ++)
            bfs(n, g, s, dis[s]);

//        for(const vector<int>& d: dis){
//            for(int e: d) cout << e << ' ';
//            cout << '\n';
//        }

        int res = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        for(int s = 0; s < n; s ++)
            res = min(res, dfs(n, g, s, 1 << s, dis, dp));
        return res;
    }

private:
    int dfs(int n, vector<vector<int>>& g, int u, int state,
            const vector<vector<int>>& dis, vector<vector<int>>& dp){

        if(state + 1 == (1 << n)) return 0;
        if(dp[u][state] != -1) return dp[u][state];

        int res = INT_MAX;
        for(int i = 0; i < n; i ++)
            if((state & (1 << i)) == 0)
                res = min(res, dis[u][i] + dfs(n, g, i, state + (1 << i), dis, dp));
        return dp[u][state] = res;
    }

    void bfs(int n, const vector<vector<int>>& g, int s, vector<int>& dis){

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        dis[s] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: g[u])
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                    dis[v] = dis[u] + 1;
                }
        }
    }
};


int main() {

    vector<vector<int>> g1 = {{1,2,3},{0},{0},{0}};
    cout << Solution().shortestPathLength(g1) << endl;
    // 4

    vector<vector<int>> g2 = {{1},{0, 2, 4},{1, 3, 4},{2}, {1, 2}};
    cout << Solution().shortestPathLength(g2) << endl;
    // 4


    return 0;
}
