/// Source : https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/description/
/// Author : liuyubobobo
/// Time   : 2018-08-05

#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <queue>
#include <numeric>

using namespace std;


/// Dijkstra
/// Time Complexity: O(ElogN)
/// Space Complexity: O(E + N)
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {

        vector<unordered_set<int>> g(N, unordered_set<int>());
        map<pair<int, int>, int> edges_map;
        map<pair<int, int>, int> used_edges;
        for(const vector<int>& edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].insert(v);
            g[v].insert(u);
            edges_map[make_pair(u, v)] = edges_map[make_pair(v, u)] = w;
            used_edges[make_pair(u, v)] = used_edges[make_pair(v, u)] = 0;
        }

        vector<bool> visited(N, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        while(!pq.empty()){
            int cur = pq.top().second;
            int step = pq.top().first;
            pq.pop();

            if(!visited[cur]){
                visited[cur] = true;
                for(int next: g[cur]){
                    pair<int, int> p = make_pair(cur, next);
                    if(step + edges_map[p] + 1 <= M){
                        used_edges[p] = edges_map[p];
                        pq.push(make_pair(step + edges_map[p] + 1, next));
                    }
                    else
                        used_edges[p] = max(used_edges[p], M - step);
                }
            }
        }

        int res = accumulate(visited.begin(), visited.end(), 0);
        for(const vector<int>& edge: edges){
            int u = edge[0], v = edge[1];
            res += min(used_edges[make_pair(u, v)] + used_edges[make_pair(v, u)],
                        edge[2]);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> edges1 = {{0, 1, 10}, {0, 2, 1}, {1, 2, 2}};
    cout << Solution().reachableNodes(edges1, 6, 3) << endl; // 13

    vector<vector<int>> edges2 = {{0, 1, 4}, {1, 2, 6}, {0, 2, 8}, {1, 3, 1}};
    cout << Solution().reachableNodes(edges2, 10, 4) << endl; // 23

    vector<vector<int>> edges3 =
        {{0, 3, 8}, {0, 1, 4}, {2, 4, 3}, {1, 2, 0}, {1, 3, 9},
         {0, 4, 7}, {3, 4, 9}, {1, 4, 4}, {0, 2, 7}, {2, 3, 1}};
    cout << Solution().reachableNodes(edges3, 8, 5) << endl; // 40

    vector<vector<int>> edges4 = {{2, 4, 2}, {3, 4, 5}, {2, 3, 1}, {0, 2, 1}, {0, 3, 5}};
    cout << Solution().reachableNodes(edges4, 14, 5) << endl; // 18

    return 0;
}