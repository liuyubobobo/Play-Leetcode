/// Source : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
/// Author : liuyubobobo
/// Time   : 2020-03-06

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(VElogE)
/// Space Complexity: O(V)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<map<int, int>> g(n);
        for(const vector<int>& v: edges)
            g[v[0]][v[1]] = v[2], g[v[1]][v[0]] = v[2];

        int minNum = INT_MAX, res = -1;
        for(int i = 0; i < n; i ++){
            int num = dij(g, i, distanceThreshold);
//            cout << i << " : " << num << endl;
            if(num <= minNum) minNum = num, res = i;
        }
        return res;
    }

private:
    int dij(const vector<map<int, int>>& g, int v, int distanceThreshold){

        int n = g.size();
        vector<int> dis(n, INT_MAX);
        vector<int> visited(n, false);

        dis[v] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, v));
        while(!pq.empty()){
            int cur = pq.top().second, d = -pq.top().first;
            pq.pop();

            if(visited[cur]) continue;
            visited[cur] = true;
            for(const pair<int, int>& p: g[cur])
                if(!visited[p.first] && d + p.second < dis[p.first]){
                    dis[p.first] = d + p.second;
                    pq.push(make_pair(- dis[p.first], p.first));
                }
        }

        int res = 0;
        for(int e: dis) res += (e <= distanceThreshold);
//        cout << v << " dis : "; for(int e: dis) cout << e << " "; cout << endl;
        return res;
    }
};


int main() {

    vector<vector<int>> edges = {
            {0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}
    };
    cout << Solution().findTheCity(5, edges, 2) << endl;
    // 0

    return 0;
}
