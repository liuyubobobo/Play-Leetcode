#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {

        vector<list<int>> g(n);
        for(const vector<int>& e : edges){
            int u = e[0], v = e[1];
            g[u].push_back(v), g[v].push_back(u);
        }

        int res = INT_MAX;
        vector<bool> in_cycle(n, false);
        for(int i = 0; i < n; i ++){
            if(in_cycle[i]) continue;

            vector<int> path;
            vector<bool> visited(n, false);
            res = min(res, dfs(g, i, -1, path, visited, in_cycle));
        }
        return res == INT_MAX ? -1 : res;
    }

private:
    int dfs(const vector<list<int>>& g, int u, int p,
            vector<int>& path, vector<bool>& visited, vector<bool>& in_cycle){

        visited[u] = true;
        path.push_back(u);

        int res = INT_MAX;
        for(int v : g[u]){
            if(!visited[v])
                res = min(res, dfs(g, v, u, path, visited, in_cycle));
            else if(v != p){
                int len = 0;
                for(int i = path.size() - 1; i >= 0; i --){
                    len ++;
                    in_cycle[path[i]] = true;
                    if(path[i] == v) break;
                }
                res = min(res, len);
            }
        }
        visited[u] = false;
        path.pop_back();
        return res;
    }
};


int main() {

    vector<vector<int>> edges1 = {{2,1},{0,1},{4,1},{3,0},{1,3}};
    cout << Solution().findShortestCycle(5, edges1) << '\n';
    // 3

    return 0;
}
