/// Source : https://leetcode.com/problems/loud-and-rich/
/// Author : liuyubobobo
/// Time   : 2021-12-14

#include <iostream>
#include <vector>

using namespace std;


/// DAG DP
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        vector<vector<int>> g(n);
        for(const vector<int>& e: richer) g[e[1]].push_back(e[0]);

        vector<bool> visited(n, false);
        vector<pair<int, int>> res(n, {-1, -1}); // value, index
        for(int i = 0; i < n; i ++)
            if(!visited[i])
                dfs(g, i, quiet, visited, res);

        vector<int> ret(n);
        for(int i = 0; i < n; i ++) ret[i] = res[i].second;
        return ret;
    }

private:
    void dfs(const vector<vector<int>>& g, int u, const vector<int>& quiet,
             vector<bool>& visited, vector<pair<int, int>>& res){

        visited[u] = true;
        res[u] = {quiet[u], u};
        for(int v: g[u]){
            if(!visited[v])
                dfs(g, v, quiet, visited, res);
            if(res[v].first < res[u].first) res[u] = res[v];
        }
    }
};


int main() {

    return 0;
}
