/// Source : https://leetcode.com/problems/critical-connections-in-a-network/
/// Author : liuyubobobo
/// Time   : 2019-09-14

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Finding Bridge Algorithm (Cut-Edge)
/// Time Complexity: O(V+E)
/// Space Complexity: O(V)
class Solution {

private:
    vector<vector<int>> res;
    vector<int> order, low;
    int cnt = 0;

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<unordered_set<int>> g(n);
        for(const vector<int>& e: connections)
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);

        order.resize(n, -1);
        low.resize(n, -1);
        cnt = 0;
        dfs(g, 0, -1);
        return res;
    }

private:
    void dfs(const vector<unordered_set<int>>& g, int v, int parent){

        order[v] = cnt ++;
        low[v] = order[v];
        for(int w: g[v])
            if(order[w] == -1){
                dfs(g, w, v);
                low[v] = min(low[v], low[w]);
                if(low[w] > order[v])
                    res.push_back({v, w});
            }
            else if(w != parent)
                low[v] = min(low[v], low[w]);
    }
};


int main() {
    
    return 0;
}