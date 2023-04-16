/// Source : https://leetcode.com/problems/the-most-similar-path-in-a-graph/description/
/// Author : liuyubobobo
/// Time   : 2023-04-15

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>

using namespace std;


/// dij
/// Time Complexity: init: O(|edges|)
///                  addEdge: O(1)
///                  query: O(|E|log|E|)
/// Space Complexity: O(|V| + |E|)
class Graph {

private:
    const int INF = INT_MAX / 2;
    int n;
    vector<list<pair<int, int>>> g;

public:
    Graph(int n, vector<vector<int>>& edges) : n(n), g(n) {
        for(const vector<int>& e: edges){
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        g[u].push_back({v, w});
    }

    int shortestPath(int s, int t) {

        vector<bool> visited(n, false);
        vector<int> dis(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second; pq.pop();

            if(visited[u]) continue;
            visited[u] = true;
            if(u == t) return d;

            for(const auto& [v, w]: g[u])
                if(d + w < dis[v]) dis[v] = d + w, pq.push({dis[v], v});
        }
        return -1;
    }
};

int main() {

    return 0;
}
