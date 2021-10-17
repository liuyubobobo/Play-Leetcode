/// Source : https://leetcode.com/problems/second-minimum-time-to-reach-destination/
/// Author : liuyubobobo
/// Time   : 2021-10-17

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


/// Dijkstra Modified
/// Time Complexity: O((n + m) * logm)
/// Space Complexity: O(n + m)
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {

        vector<vector<int>> g(n);
        for(const vector<int>& e: edges){
            int u = e[0] - 1, v = e[1] - 1;
            g[u].push_back(v), g[v].push_back(u);
        }

        vector<vector<int>> dis(n, vector<int>(2, INT_MAX));
        vector<bool> visited(n, false);
        // t, u
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dis[0][0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second;
            pq.pop();

            if(d > dis[u][1]) continue;

            for(int v: g[u])
                if(!visited[v]){
                    int nextd = d + (d % (2 * change) < change ? 0 : (2 * change - d % (2 * change))) + time;
                    if(nextd < dis[v][1] && nextd != dis[v][0]){
                        dis[v][1] = nextd;
                        pq.push({nextd, v});
                        if(dis[v][0] > dis[v][1]) swap(dis[v][0], dis[v][1]);
                    }
                }
        }

//        cout << dis[n - 1][0] << ' ' << dis[n - 1][1] << '\n';
        return dis[n - 1][1];
    }
};


int main() {

    vector<vector<int>> edges1 = {
            {1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}
    };
    cout << Solution().secondMinimum(5, edges1, 3, 5) << endl;
    // min_t : 6
    // 13

    vector<vector<int>> edges2 = {
            {1, 2}
    };
    cout << Solution().secondMinimum(2, edges2, 3, 2) << endl;
    // min_t : 3
    // 11

    return 0;
}
