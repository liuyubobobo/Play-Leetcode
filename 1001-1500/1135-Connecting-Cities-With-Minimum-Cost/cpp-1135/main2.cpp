/// Source : https://leetcode.com/problems/connecting-cities-with-minimum-cost/
/// Author : liuyubobobo
/// Time   : 2019-07-25

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <numeric>

using namespace std;


/// Prim
/// Time Complexity: O(ElogE)
/// Space Complexity: O(V)
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {

        vector<unordered_map<int, int>> g(N);
        for(vector<int>& c: connections){
            g[--c[0]].count(--c[1]);
            if(!g[c[0]].count(c[1]) || c[2] < g[c[0]][c[1]]){
                g[c[0]][c[1]] = c[2];
                g[c[1]][c[0]] = c[2];
            }
        }

        vector<bool> visited(N, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(const pair<int, int>& p: g[0])
            pq.push(make_pair(p.second, p.first));
        visited[0] = true;
        int res = 0;
        while(!pq.empty()){
            int v = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(!visited[v]){
                res += weight;
                visited[v] = true;
                for(const pair<int, int>& p: g[v])
                    if(!visited[p.first])
                        pq.push(make_pair(p.second, p.first));
            }
        }
        return accumulate(visited.begin(), visited.end(), 0) == N ? res : -1;
    }
};


int main() {

    vector<vector<int>> edges1 = {{1, 2, 5}, {1, 3, 6}, {2, 3, 1}};
    cout << Solution().minimumCost(3, edges1) << endl;
    return 0;
}