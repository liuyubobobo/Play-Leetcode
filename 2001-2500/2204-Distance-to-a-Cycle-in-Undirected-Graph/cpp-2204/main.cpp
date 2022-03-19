/// Source : https://leetcode.com/problems/distance-to-a-cycle-in-undirected-graph/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Graph get cycle and BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        vector<int> cycle = get_cycle(n, g);
//        for(int e: cycle) cout << e << ' '; cout << '\n';

        queue<int> q;
        vector<int> res(n, -1);
        for(int e: cycle){
            q.push(e);
            res[e] = 0;
        }

        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int v: g[u]){
                if(res[v] != -1) continue;
                res[v] = res[u] + 1;
                q.push(v);
            }
        }
        return res;
    }

private:
    vector<int> get_cycle(int n, const vector<vector<int>>& g){

        vector<bool> visited(n, false);
        vector<int> pre(n, -1);
        vector<int> cycle;
        dfs(g, 0, -1, visited, pre, cycle);
        return cycle;
    }

    bool dfs(const vector<vector<int>>& g, int u, int p,
             vector<bool>& visited, vector<int>& pre, vector<int>& cycle){

        visited[u] = true;
        pre[u] = p;
        for(int v: g[u]){
            if(v == p) continue;
            if(!visited[v]){
                if(dfs(g, v, u, visited, pre, cycle)) return true;
            }
            else{
                cycle.push_back(v);
                int cur = u;
                while(cur != v){
                    cycle.push_back(cur);
                    cur = pre[cur];
                }
                return true;
            }
        }
        return false;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<vector<int>> edges1 = {{1,2},{2,3},{3,4},{4,1},{0,1},{5,2},{6,5}};
    print_vec(Solution().distanceToCycle(7, edges1));
    // 1 0 0 0 0 1 2

    vector<vector<int>> edges2 = {{0,1},{1,2},{0,2},{2,6},{6,7},{6,8},{1,3},{3,4},{3,5}};
    print_vec(Solution().distanceToCycle(9, edges2));
    // 0,0,0,1,2,2,1,2,2

    return 0;
}
