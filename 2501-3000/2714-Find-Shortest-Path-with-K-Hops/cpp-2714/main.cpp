/// Source : https://leetcode.com/problems/find-shortest-path-with-k-hops/description/
/// Author : liuyubobobo
/// Time   : 2023-06-03

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(nk * log(n * k))
/// Space Complexity: O(n * k)
class Solution {

private:
    const int INF = INT_MAX / 2;

public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int t, int k) {

        vector<list<pair<int, int>>> g(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w}), g[v].push_back({u, w});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> dis(n, vector<int>(k + 1, INF));
        vector<vector<bool>> visited(n, vector<bool>(k + 1, false));
        pq.push({0, {s, k}});
        dis[s][k] = 0;

        while(!pq.empty()) {
            const pair<int, pair<int, int>> p = pq.top(); pq.pop();
            int d = p.first, u = p.second.first, h = p.second.second;

            if(visited[u][h]) continue;
            visited[u][h] = true;
//            cout << u << " " << h << " " << d << endl;

            if(h){
                for(const pair<int, int>& e : g[u]) {
                    int v = e.first, w = e.second;
                    if(!visited[v][h - 1] && dis[v][h - 1] > d) {
                        dis[v][h - 1] = d;
                        pq.push({d, {v, h - 1}});
                    }
                }
            }

            for(const pair<int, int>& e : g[u]) {
                int v = e.first, w = e.second;
                if(!visited[v][h] && dis[v][h] > d + w) {
                    dis[v][h] = d + w;
                    pq.push({d + w, {v, h}});
                }
            }
        }
        return *min_element(dis[t].begin(), dis[t].end());
    }
};


int main() {

    vector<vector<int>> edges1 = {{0,1,4},{0,2,2},{2,3,6}};
    cout << Solution().shortestPathWithHops(4, edges1, 1, 3, 2) << endl;

    return 0;
}
