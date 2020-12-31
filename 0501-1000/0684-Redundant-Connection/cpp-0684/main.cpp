/// Source : https://leetcode.com/problems/redundant-connection/description/
/// Author : liuyubobobo
/// Time   : 2017-12-01

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

/// Check Connection Backwards
/// Time Complexity: O(e^2)
/// Space Complexity: O(e)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, unordered_set<int>> g = createGraph(edges);
        for(int i = edges.size() - 1 ; i >= 0 ; i --){
            vector<int> edge = edges[i];
            g[edge[0]].erase(edge[1]);
            g[edge[1]].erase(edge[0]);

            if(connected(g, edge[0]))
                return edge;

            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }

        assert(false);
    }

private:
    unordered_map<int, unordered_set<int>> createGraph(const vector<vector<int>>& edges){

        unordered_map<int, unordered_set<int>> g;
        for(const vector<int>& edge: edges){
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        return g;
    }

    bool connected(const unordered_map<int, unordered_set<int>>& g, int v){

        unordered_set<int> visited;
        dfs(g, v, visited);

        for(const pair<int, unordered_set<int>>& p: g)
            if(visited.find(p.first) == visited.end())
                return false;

        return true;
    }

    void dfs(const unordered_map<int, unordered_set<int>>& g, int v,
                unordered_set<int>& visited){

        visited.insert(v);
        for(int next: g.find(v)->second)
            if(visited.find(next) == visited.end())
                dfs(g, next, visited);
    }
};


void printVec(const vector<int>& v){
    for(int e: v)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> vec1 = {{1, 2}, {1, 3}, {2, 3}};
    printVec(Solution().findRedundantConnection(vec1));

    vector<vector<int>> vec2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    printVec(Solution().findRedundantConnection(vec2));

    return 0;
}