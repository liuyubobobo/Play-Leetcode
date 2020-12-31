/// Source : https://leetcode.com/problems/redundant-connection/description/
/// Author : liuyubobobo
/// Time   : 2017-12-01

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

/// From start, add edges into the graph
/// The first edge make a circle is the result
/// Time Complexity: O(e^2)
/// Space Complexity: O(e)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        unordered_map<int, unordered_set<int>> g;
        for(const vector<int>& edge: edges)
            if(connected(g, edge[0], edge[1]))
                return edge;
            else{
                g[edge[0]].insert(edge[1]);
                g[edge[1]].insert(edge[0]);
            }

        assert(false);
    }

private:

    bool connected(const unordered_map<int, unordered_set<int>>& g, int s, int t){

        unordered_set<int> visited;
        return dfs(g, s, t, visited);
    }

    bool dfs(const unordered_map<int, unordered_set<int>>& g, int s, int t,
             unordered_set<int>& visited){

        if(s == t)
            return true;

        visited.insert(s);

        unordered_map<int, unordered_set<int>>::const_iterator iter = g.find(s);
        if(iter != g.end()){
            for(int next: iter->second)
                if(visited.find(next) == visited.end())
                    if(dfs(g, next, t, visited))
                        return true;
        }

        return false;
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