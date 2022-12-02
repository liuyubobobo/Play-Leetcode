/// Source : https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/description/
/// Author : liuyubobobo
/// Time   : 2022-11-29

#include <iostream>
#include <vector>
#include <list>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {

        int n = roads.size() + 1;
        vector<list<int>> tree(n);
        for(const vector<int>& road: roads){
            int a = road[0], b = road[1];
            tree[a].push_back(b), tree[b].push_back(a);
        }

        vector<int> sz(n, 0);
        dfs_sz(tree, 0, 0, sz);

        long long res = 0;
        for(int i = 1; i < n; i ++)
            res += sz[i] / seats + !!(sz[i] % seats);
        return res;
    }

private:
    int dfs_sz(const vector<list<int>>& tree, int u, int p, vector<int>& sz){

        int res = 1;
        for(int v: tree[u]){
            if(v == p) continue;
            res += dfs_sz(tree, v, u, sz);
        }
        return sz[u] = res;
    }
};


int main() {

    return 0;
}
