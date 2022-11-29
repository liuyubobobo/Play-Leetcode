/// Source : https://leetcode.com/problems/most-profitable-path-in-a-tree/description/
/// Author : liuyubobobo
/// Time   : 2022-11-28

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        int n = edges.size() + 1;

        vector<list<int>> tree(n);
        for(const vector<int>& edge: edges){
            int a = edge[0], b = edge[1];
            tree[a].push_back(b), tree[b].push_back(a);
        }

        vector<int> parent(n, 0);
        dfs_parent(tree, 0, 0, parent);

        vector<int> bob_path = {bob};
        while(bob_path.back() != 0) bob_path.push_back(parent[bob_path.back()]);

        int res = INT_MIN, ares = 0, bres = 0;
        vector<int> visited(n, 0);
        dfs(tree, 0, 0, 0, visited, bob_path, amount, ares, bres, res);
        return res;
    }

private:
    void dfs(const vector<list<int>>& tree, int u, int p, int index,
             vector<int>& visited, const vector<int>& bob_path, const vector<int>& amount,
             int& ares, int& bres, int& res){

        if(index < bob_path.size()){
            if(u == bob_path[index]){
                ares += amount[u] / 2, bres += amount[u] / 2;
                assert(visited[u] == 0);
                visited[u] |= 3;
            }
            else{
                if(!visited[u])
                    ares += amount[u], visited[u] |= 1;
                if(!visited[bob_path[index]])
                    bres += amount[bob_path[index]], visited[bob_path[index]] |= 2;
            }
        }
        else{
            if(!visited[u]) ares += amount[u], visited[u] |= 1;
        }

        if(tree[u].size() == 1 && u){
            res = max(res, ares);
        }

        for(int v: tree[u]){
            if(v == p) continue;
            dfs(tree, v, u, index + 1, visited, bob_path, amount, ares, bres, res);
        }

        if(index < bob_path.size()){
            if(u == bob_path[index]){
                assert(visited[u] == 3);
                ares -= amount[u] / 2, bres -= amount[u] / 2;
                visited[u] = 0;
            }
            else{
                if(visited[u] & 1) ares -= amount[u], visited[u] -= 1;
                if(visited[bob_path[index]] & 2) bres -= amount[bob_path[index]], visited[bob_path[index]] -= 2;
            }
        }
        else{
            if(visited[u] & 1) ares -= amount[u], visited[u] -= 1;
        }
    }

    void dfs_parent(const vector<list<int>>& tree, int u, int p, vector<int>& parent){

        parent[u] = p;
        for(int v: tree[u]){
            if(v == p) continue;
            dfs_parent(tree, v, u, parent);
        }
    }
};


int main() {

    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 3}};
    vector<int> amount1 = {-5644,-6018,1188,-8502};
    cout << Solution().mostProfitablePath(edges1, 3, amount1) << '\n';

    return 0;
}
