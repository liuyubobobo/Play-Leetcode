/// Source : https://leetcode.com/problems/reachable-nodes-with-restrictions/
/// Author : liuyubobobo
/// Time   : 2022-08-10

#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        set<int> restricted_set(restricted.begin(), restricted.end());

        vector<list<int>> tree(n);
        for(const vector<int>& p: edges){
            int u = p[0], v = p[1];
            tree[u].push_back(v), tree[v].push_back(u);
        }

        return dfs(tree, 0, -1, restricted_set);
    }

private:
    int dfs(const vector<list<int>>& tree, int u, int p, set<int>& restricted_set){

        if(restricted_set.count(u)) return 0;

        int res = 1;
        for(int v: tree[u]){
            if(v == p) continue;
            res += dfs(tree, v, u, restricted_set);
        }
        return res;
    }
};


int main() {


    return 0;
}
