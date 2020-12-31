/// Source : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;


/// DFS, record edges' direction on adjacent list
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<unordered_map<int, bool>> g(n);
        for(const vector<int>& e: connections)
            g[e[0]][e[1]] = true, g[e[1]][e[0]] = false;

        vector<bool> visited(n, false);
        return dfs(g, 0, visited);
    }

private:
    int dfs(const vector<unordered_map<int, bool>>& g, int v, vector<bool>& visited){

        visited[v] = true;
        int res = 0;
        for(const pair<int, bool> &p: g[v])
            if(!visited[p.first])
                res += p.second + dfs(g, p.first, visited);
        return res;
    }
};


int main() {

    return 0;
}
