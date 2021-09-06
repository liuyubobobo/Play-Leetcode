/// Source : https://leetcode.com/problems/sum-of-distances-in-tree/
/// Author : liuyubobobo
/// Time   : 2021-09-05

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> tree(n);
        for(const vector<int>& e: edges)
            tree[e[0]].push_back(e[1]), tree[e[1]].push_back(e[0]);

        vector<int> subnodes(n, 0);
        dfs_subnodes(tree, 0, -1, subnodes);

        vector<int> subnodes_dis(n, 0);
        dfs_subnodes_dis(tree, 0, -1, subnodes, subnodes_dis);

        vector<int> ret(n, 0);
        dfs_res(n, tree, 0, -1, subnodes, subnodes_dis, ret);
        return ret;
    }

private:
    void dfs_res(int n, const vector<vector<int>>& tree, int u, int p,
                 const vector<int>& subnodes, const vector<int>& subnodes_dis,
                 vector<int>& ret){

        if(p == -1){
            ret[u] = subnodes_dis[u];
            for(int v: tree[u]) dfs_res(n, tree, v, u, subnodes, subnodes_dis, ret);
            return;
        }

        ret[u] = subnodes_dis[u] + ret[p] - (subnodes_dis[u] + subnodes[u]) + n - subnodes[u];
        for(int v: tree[u])
            if(v != p)
                dfs_res(n, tree, v, u, subnodes, subnodes_dis, ret);
        return;
    }

    int dfs_subnodes_dis(const vector<vector<int>>& tree, int u, int p,
                         const vector<int>& subnodes, vector<int>& subnodes_dis){

        int res = 0;
        for(int v: tree[u])
            if(v != p){
                res += dfs_subnodes_dis(tree, v, u, subnodes, subnodes_dis) + subnodes[v];
            }
        subnodes_dis[u] = res;
        return res;
    }

    int dfs_subnodes(const vector<vector<int>>& tree, int u, int p, vector<int>& subnodes){

        int res = 1;
        for(int v: tree[u])
            if(v != p){
                res += dfs_subnodes(tree, v, u, subnodes);
            }
        subnodes[u] = res;
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << endl;
}

int main() {

    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    print_vec(Solution().sumOfDistancesInTree(6, edges1));
    // 8 12 6 10 10 10

    vector<vector<int>> edges2 = {};
    print_vec(Solution().sumOfDistancesInTree(1, edges2));
    // 0

    return 0;
}
