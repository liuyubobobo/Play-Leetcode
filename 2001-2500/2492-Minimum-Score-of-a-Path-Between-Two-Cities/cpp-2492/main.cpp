/// Source : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/
/// Author : liuyubobobo
/// Time   : 2022-12-19

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


/// Greedy
/// Time Complexity: O(eloge + (v + e) + e)
/// Space Complexity: O(v + e)
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        sort(roads.begin(), roads.end(),
             [](const vector<int>& road1, const vector<int>& road2){
            return road1[2] < road2[2];
        });

        vector<list<int>> g(n);
        for(int i = 0; i < roads.size(); i ++){
            int u = roads[i][0] - 1, v = roads[i][1] - 1;
            g[u].push_back(v), g[v].push_back(u);
        }

        vector<bool> visited_s(n, false);
        dfs(g, 0, 0, visited_s);

        vector<bool> visited_t(n, false);
        dfs(g, n - 1, n - 1, visited_t);

        for(const vector<int>& road: roads){
            int u = road[0] - 1, v = road[1] - 1, w = road[2];
            if(visited_s[u] && visited_t[v]) return w;
            if(visited_s[v] && visited_t[u]) return w;
        }
        return -1;
    }

private:
    void dfs(const vector<list<int>>& g, int u, int p, vector<bool>& visited){
        visited[u] = true;
        for(int v: g[u]){
            if(v == p || visited[v]) continue;
            dfs(g, v, u, visited);
        }
    }
};


int main() {

    return 0;
}
