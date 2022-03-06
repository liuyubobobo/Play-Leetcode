/// Source : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
/// Author : liuyubobobo
/// Time   : 2022-03-05

#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


/// Topological Sort + Bitset
/// Time Complexity: O(n + m)
/// Space Complexity: O(n + m)
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0]].push_back(e[1]);

        vector<int> in_degrees(n, 0);
        for(int u = 0; u < n; u ++)
            for(int v: g[u]) in_degrees[v] ++;

        queue<int> q;
        for(int u = 0; u < n; u ++)
            if(in_degrees[u] == 0) q.push(u);
        vector<bitset<1000>> res(n);

        while(!q.empty()){
            int u = q.front(); q.pop();

            for(int v: g[u]){
                res[v].set(u);
                res[v] |= res[u];
                in_degrees[v] --;
                if(in_degrees[v] == 0) q.push(v);
            }
        }

        vector<vector<int>> ret(n);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(res[i].test(j)) ret[i].push_back(j);
        return ret;
    }
};


int main() {

    return 0;
}
