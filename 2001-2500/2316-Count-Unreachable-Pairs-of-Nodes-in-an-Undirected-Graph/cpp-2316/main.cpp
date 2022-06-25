/// Source : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
/// Author : liuyubobobo
/// Time   : 2022-06-25

#include <iostream>
#include <vector>

using namespace std;


/// CC
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges){
            int u = e[0], v = e[1];
            g[u].push_back(v), g[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<long long> cc_sz;
        for(int i = 0; i < n; i ++)
            if(!visited[i]){
                cc_sz.push_back(dfs(g, i, visited));
            }

        long long res = 0;
        for(long long sz: cc_sz)
            res += sz * (n - sz);
        return res / 2;
    }

private:
    int dfs(const vector<vector<int>>& g, int u, vector<bool>& visited){

        visited[u] = true;
        int res = 1;
        for(int v: g[u]){
            if(visited[v]) continue;
            res += dfs(g, v, visited);
        }
        return res;
    }
};


int main() {

    return 0;
}
