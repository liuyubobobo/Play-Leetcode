/// Source : https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;


/// Dijkstra
/// Time Complexity: O(n^2 * logn)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {

        set<pair<int, int>> vertexs;
        vertexs.insert({start[0], start[1]});
        vertexs.insert({target[0], target[1]});
        for(const vector<int>& v: specialRoads) {
            vertexs.insert({v[0], v[1]});
            vertexs.insert({v[2], v[3]});
        }

        vector<pair<int, int>> index2v(vertexs.begin(), vertexs.end());
        map<pair<int, int>, int> v2index;
        for(int i = 0; i < index2v.size(); i++) v2index[index2v[i]] = i;

        int n = index2v.size();
        int s = v2index[{start[0], start[1]}], t = v2index[{target[0], target[1]}];

        vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                g[i][j] = g[j][i] = get_dis(index2v[i], index2v[j]);

        for(const vector<int>& v: specialRoads) {
            int a = v2index[{v[0], v[1]}], b = v2index[{v[2], v[3]}], w = v[4];
            if(w < g[a][b]) g[a][b] = w;
        }


        return dij(n, g, s, t);
    }

private:
    int dij(int n, const vector<vector<int>>& g, int s, int t){

        vector<bool> visited(n, false);
        vector<int> dis(n, INT_MAX / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, s});
        dis[s] = 0;
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();

            if(visited[u]) continue;
            visited[u] = true;

            dis[u] = d;
            for(int v = 0; v < n; v ++){
                int w = g[u][v];
                if(!visited[v] && dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis[t];
    }

    int get_dis(const pair<int, int>& p1, const pair<int, int>& p2){
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }
};


int main() {

    vector<int> start1 = {1, 1}, target1 = {4, 5};
    vector<vector<int>> specialRoads1 = {{1, 2, 3, 3, 2}, {3, 4, 4, 5, 1}};
    cout << Solution().minimumCost(start1, target1, specialRoads1) << endl;
    // 5

    return 0;
}
