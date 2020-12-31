/// Source : https://leetcode.com/problems/redundant-connection-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-12-01

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cassert>

using namespace std;

/// First, see whether we can find a vertex with 0-indegree.
/// If we can, wo got the root, try to erase one of the two edges
/// for the 2-indegree vertex;
/// Otherwise, there's a loop in our graph, find the loop and erase the last edge
///
/// Time Complexity: O(e)
/// Space Complexity: O(e)
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        unordered_set<int> vertex;
        for(const vector<int>& edge: edges){
            vertex.insert(edge[0]);
            vertex.insert(edge[1]);
        }

        unordered_map<int, unordered_set<int>> g = createGraph(vertex, edges);
        unordered_map<int, int> indegrees;
        for(const vector<int>& edge: edges){
            if(indegrees.find(edge[0]) == indegrees.end())
                indegrees[edge[0]] = 0;
            if(indegrees.find(edge[1]) == indegrees.end())
                indegrees[edge[1]] = 0;
            indegrees[edge[1]] += 1;
        }

        int root = -1, two = -1;
        for(const pair<int, int>& indegree: indegrees)
            if(indegree.second == 0)
                root = indegree.first;
            else if(indegree.second == 2)
                two = indegree.first;

        if(root != -1){
            assert(two != -1);
            return tryFindRedundantDirectedConnectionByEraseEdgeTo(
                    two, g, edges, root);
        }

        /// Otherwise, find the Loop
        vector<int> loopv;
        findLoop(g, edges[0][0], loopv);

        loopv.push_back(*loopv.begin());
        reverse(loopv.begin(), loopv.end());
        set<pair<int, int>> loop_edges;
        for(int i = 0 ; i < loopv.size() - 1; i ++){
            pair<int, int> edge = make_pair(loopv[i], loopv[i+1]);
            loop_edges.insert(edge);
        }

        for(int i = edges.size() - 1; i >= 0 ; i --){
            pair<int, int> edge = make_pair(edges[i][0], edges[i][1]);
            if(loop_edges.find(edge) != loop_edges.end())
                return edges[i];
        }

        assert(false);
    }

private:
    unordered_map<int, unordered_set<int>> createGraph(
            const unordered_set<int> vertex, const vector<vector<int>>& edges){

        unordered_map<int, unordered_set<int>> g;
        for(int v: vertex)
            g[v].clear();

        for(const vector<int>& edge: edges)
            g[edge[0]].insert(edge[1]);

        return g;
    }

    vector<int> tryFindRedundantDirectedConnectionByEraseEdgeTo(
            int v, unordered_map<int, unordered_set<int>>& g,
            const vector<vector<int>>& edges, int root){

        for(int i = edges.size() - 1 ; i >= 0 ; i --){
            vector<int> edge = edges[i];
            if(edge[1] == v){
                g[edge[0]].erase(edge[1]);
                if(connected(g, root))
                    return edge;
                g[edge[0]].insert(edge[1]);
            }
        }

        assert(false);
    }

    bool connected(const unordered_map<int, unordered_set<int>>& g, int root){

        unordered_set<int> visited;
        dfs(g, root, visited);
        for(auto& e: g)
            if(visited.find(e.first) == visited.end())
                return false;
        return true;
    }

    void dfs(const unordered_map<int, unordered_set<int>>& g, int v,
             unordered_set<int>& visited){

        visited.insert(v);

        unordered_map<int, unordered_set<int>>::const_iterator iter = g.find(v);
        for(int next: iter->second)
            if(visited.find(next) == visited.end())
                dfs(g, next, visited);
    }

    void findLoop(const unordered_map<int, unordered_set<int>>& g, int v,
                 vector<int>& loopv){
        unordered_set<int> visited;
        assert(findLoop(g, v, visited, loopv));
    }

    bool findLoop(const unordered_map<int, unordered_set<int>>& g, int v,
                 unordered_set<int>& visited, vector<int>& loopv){

        visited.insert(v);

        unordered_map<int, unordered_set<int>>::const_iterator iter = g.find(v);
        for(int next: iter->second)
            if(visited.find(next) != visited.end()){
                loopv.push_back(next);
                return true;
            }
            else if(findLoop(g, next, visited, loopv)){
                loopv.push_back(next);
                return true;
            }

        return false;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> vec1 = {{1, 2}, {1, 3}, {2, 3}};
    printVec(Solution().findRedundantDirectedConnection(vec1));

    vector<vector<int>> vec2 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    printVec(Solution().findRedundantDirectedConnection(vec2));

    return 0;
}