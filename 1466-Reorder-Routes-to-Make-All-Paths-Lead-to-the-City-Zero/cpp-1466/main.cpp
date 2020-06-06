/// Source : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
/// Author : liuyubobobo
/// Time   : 2020-05-30

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;


/// DFS, Using Map to record edges' directions
/// Time Complexity: O(V + E)
/// Space Complexity: O(E)
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<unordered_set<int>> g(n);
        map<pair<int, int>, int> directions;
        for(const vector<int>& e: connections){
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);
            directions[make_pair(e[0], e[1])] = e[0];
            directions[make_pair(e[1], e[0])] = e[0];
        }

        vector<bool> visited(n, false);
        return dfs(g, 0, -1, directions, visited);
    }

private:
    int dfs(const vector<unordered_set<int>>& g, int v, int p,
            map<pair<int, int>, int>& directions, vector<bool>& visited){

        visited[v] = true;
        int res = 0;
        if(p != -1) res += (directions[make_pair(v, p)] == p);
        for(int next: g[v])
            if(!visited[next]) res += dfs(g, next, v, directions, visited);
        return res;
    }
};


int main() {

    return 0;
}
