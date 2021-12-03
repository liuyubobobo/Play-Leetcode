/// Source : https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/
/// Author : liuyubobobo
/// Time   : 2021-12-03

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(discount * E * log(discount * E))
/// Space Complexity: O(discount * V)
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {

        vector<vector<pair<int, int>>> g(n);
        for(const vector<int>& e: highways){
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w}), g[v].push_back({u, w});
        }

        vector<vector<int>> dis(discounts + 1, vector<int>(n, INT_MAX / 2));
        vector<vector<bool>> visited(discounts + 1, vector<bool>(n, false));

        // dis, {discount, u}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {discounts, 0}});
        while(!pq.empty()){
            int d = pq.top().first;
            int discount = pq.top().second.first, u = pq.top().second.second;
            pq.pop();

            if(visited[discount][u]) continue;
            visited[discount][u] = true;

            for(const pair<int, int>& p: g[u]){
                int v = p.first, w = p.second;
                if(d + w < dis[discount][v]){
                    dis[discount][v] = d + w;
                    pq.push({d + w, {discount, v}});
                }
                if(discount && d + w / 2 < dis[discount - 1][v]){
                    dis[discount - 1][v] = d + w / 2;
                    pq.push({d + w / 2, {discount - 1, v}});
                }
            }
        }

        int res = INT_MAX / 2;
        for(int discount = 0; discount <= discounts; discount ++)
            res = min(res, dis[discount][n - 1]);
        return res == INT_MAX / 2 ? -1 : res;
    }
};


int main() {

    return 0;
}
