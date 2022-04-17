#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {

        int n = -1;
        for(const vector<int>& e: edges){
            n = max(n, e[0]);
            n = max(n, e[1]);
        }
        n ++;

        vector<vector<pair<int, int>>> g(n);
        for(const vector<int>& e: edges){
            int u = e[0], v = e[1];
            g[u].emplace_back(scores[v], v);
            g[v].emplace_back(scores[u], u);
        }

        for(int i = 0; i < n; i ++)
            sort(g[i].begin(), g[i].end(), greater<pair<int, int>>());

        int res = -1;
        for(const vector<int>& e: edges){
            int u = e[0], v = e[1];
            for(int i = 0; i < 3 && i < g[u].size(); i ++)
                if(g[u][i].second != v){
                    int x = g[u][i].second;
                    for(int j = 0; j < 3 && j < g[v].size(); j ++)
                        if(g[v][j].second != u && g[v][j].second != x){
                            int y = g[v][j].second;
                            res = max(res, scores[x] + scores[u] + scores[v] + scores[y]);
                        }
                }
        }
        return res;
    }
};

int main() {

    return 0;
}
