/// Source : https://leetcode.com/problems/maximum-path-quality-of-a-graph/
/// Author : liuyubobobo
/// Time   : 2021-11-06

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS
/// Time Complexity: O(|d|^10) where d is the degree of vertexs and at most 4 according to the problem
/// Space Complexity: O(n + m)
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {

        int n = values.size();
        vector<vector<pair<int, int>>> g(n);
        for(const vector<int>& e: edges){
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        long long res = 0ll;
        vector<int> path = {0};
        dfs(n, g, 0, maxTime, path, values, res);
        return res;
    }

private:
    void dfs(int n, const vector<vector<pair<int, int>>>& g, int u, int t,
             vector<int>& path, const vector<int>& values, long long& res){

        if(u == 0){
            set<int> vset(path.begin(), path.end());
            long long tres = 0;
            for(int v: vset) tres += values[v];
            res = max(res, tres);
        }

        for(const pair<int, int>& p: g[u]){
            int v = p.first, w = p.second;
            if(t - w >= 0){
                path.push_back(v);
                dfs(n, g, v, t - w, path, values, res);
                path.pop_back();
            }
        }
    }
};


int main() {

    vector<int> values1 = {0, 32, 10, 43};
    vector<vector<int>> edges1 = {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}};
    cout << Solution().maximalPathQuality(values1, edges1, 49) << endl;
    // 75

    vector<int> values2 = {5, 10, 15, 20};
    vector<vector<int>> edges2 = {{0, 1, 10}, {1, 2, 10}, {0, 3, 10}};
    cout << Solution().maximalPathQuality(values2, edges2, 30) << endl;
    // 25

    vector<int> values3 = {1, 2, 3, 4};
    vector<vector<int>> edges3 = {{0, 1, 10}, {1, 2, 11}, {2, 3, 12}, {1, 3, 13}};
    cout << Solution().maximalPathQuality(values3, edges3, 50) << endl;
    // 7

    vector<int> values4 = {0, 1, 2};
    vector<vector<int>> edges4 = {{1, 2, 10}};
    cout << Solution().maximalPathQuality(values4, edges4, 10) << endl;
    // 0

    return 0;
}
