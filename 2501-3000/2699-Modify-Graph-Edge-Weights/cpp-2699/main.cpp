/// Source : https://leetcode.com/problems/modify-graph-edge-weights/description/
/// Author : liuyubobobo
/// Time   : 2023-05-21

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;


/// Binary Search
/// Time Complexity: O(n^2 * log(target) * n^2 * logn)
/// Space Complexity: O(n^2)
class Solution {

private:
    const long long INF = LONG_LONG_MAX / 2;
    long long MAXW = 1000000000ll;

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

        MAXW = target;

        vector<vector<long long>> g(n, vector<long long>(n, INF));
        for(const vector<int>& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if(w == -1) w = MAXW;
            g[u][v] = g[v][u] = w;
        }

        long long dis = dij(n, g, source, destination);
        if(dis < target) return {};
        if(dis == target){
            for(vector<int>& edge: edges) if(edge[2] == -1) edge[2] = MAXW;
            return edges;
        }

        for(vector<int>& edge: edges){
            if(edge[2] == -1){
                int u = edge[0], v = edge[1];
                long long l = 1, r = MAXW;
                while(l < r){
                    long long mid = (l + r) / 2;
                    g[u][v] = g[v][u] = mid;
                    long long tdis = dij(n, g, source, destination);
                    if(tdis < target) l = mid + 1;
                    else r = mid;
                }
                g[u][v] = g[v][u] = l;
            }
        }

        if(dij(n, g, source, destination) != target) return {};
        for(vector<int>& edge: edges) edge[2] = g[edge[0]][edge[1]];
        return edges;
    }

private:
    long long dij(int n, const vector<vector<long long>>& g, int s, int t){

        vector<long long> dis(n, INF);
        vector<bool> visited(n, false);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, s});
        dis[s] = 0;
        while(!pq.empty()){
            long long d = pq.top().first; int u = pq.top().second; pq.pop();
            if(visited[u]) continue;
            visited[u] = true;

            for(int v = 0; v < n; v ++){
                if(visited[v]) continue;
                long long w = g[u][v];
                if(d + w < dis[v]){
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis[t];
    }
};


void print_vec(const vector<vector<int>>& v){
    for(const vector<int>& e: v){
        for(int x: e) cout << x << ' '; cout << '\n';
    }
}

int main() {

    vector<vector<int>> edges1 = {{4, 1, -1}, {2, 0, -1}, {0, 3, -1}, {4, 3, -1}};
    print_vec(Solution().modifiedGraphEdges(5, edges1, 0, 1, 5));

    return 0;
}
