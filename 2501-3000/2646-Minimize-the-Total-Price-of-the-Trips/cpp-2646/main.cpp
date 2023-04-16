/// Source : https://leetcode.com/problems/minimize-the-total-price-of-the-trips/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <cassert>
#include <climits>

using namespace std;


/// Tree DP
/// Time Complexity: O(|trip| * n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {

        vector<list<int>> g(n);
        for(const vector<int>& e: edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v), g[v].push_back(u);
        }

        vector<int> f(n, 0);
        for(const vector<int>& trip: trips) {
            int s = trip[0], t = trip[1];

            vector<int> path = get_path(n, g, s, t);
            assert(path[0] == s && path.back() == t);
            for(int e: path) f[e] ++;
        }

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return dfs(g, 0, -1, true, f, price, dp);
    }

private:
    int dfs(const vector<list<int>>& g, int u, int p, bool can_halve,
            const vector<int>& f, const vector<int>& price, vector<vector<int>>& dp) {

        if(dp[u][can_halve] != -1) return dp[u][can_halve];

        int res = INT_MAX;
        if(can_halve){
            int tres = price[u] / 2 * f[u];
            for(int v: g[u]) {
                if(v == p) continue;
                tres += dfs(g, v, u, false, f, price, dp);
            }
            res = min(res, tres);
        }

        int tres = price[u] * f[u];
        for(int v: g[u]) {
            if(v == p) continue;
            tres += dfs(g, v, u, true, f, price, dp);
        }
        res = min(res, tres);

        return dp[u][can_halve] = res;
    }

    vector<int> get_path(int n, const vector<list<int>>& g, int s, int t){

        vector<int> pre(n, -1);
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v: g[u]) {
                if(visited[v]) continue;
                pre[v] = u;
                q.push(v);
                visited[v] = true;
            }
        }

        vector<int> path = {t};
        while(path.back() != s)
            path.push_back(pre[path.back()]);
        reverse(path.begin(), path.end());
        return path;
    }
};


int main() {

    vector<vector<int>> edges1 = {{0,1},{1,2},{1,3}};
    vector<int> price1 = {2,2,10,6};
    vector<vector<int>> trips1 = {{0,3},{2,1},{2,3}};
    cout << Solution().minimumTotalPrice(4, edges1, price1, trips1) << '\n';
    // 23

    return 0;
}
