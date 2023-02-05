/// Source : https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/description/
/// Author : liuyubobobo
/// Time   : 2023-02-05

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Tarjan critical points
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class TarjanCriticalPoint{

private:
    int n;
    vector<set<int>> g;
    set<int> critical_points;

public:
    TarjanCriticalPoint(int n): n(n), g(n){}

    void add_edge(int u, int v){
        g[u].insert(v);
        g[v].insert(u);
    }

    vector<int> get_critical_points(){
        return vector<int>(critical_points.begin(), critical_points.end());
    }

    bool solve(){

        critical_points.clear();

        vector<int> ids(n, -1), low(n, -1);
        int id = 0;
        return dfs(0, -1, id, ids, low);
    }

    bool dfs(int u, int p, int& id, vector<int>& ids, vector<int>& low){

        bool ret = (u == n - 1);
        ids[u] = low[u] = id ++;

        int children = 0;
        for(int v: g[u]){
            if(v == p) continue;
            if(ids[v] == -1){
                if(dfs(v, u, id, ids, low)) ret = true;
                low[u] = min(low[u], low[v]);
                children ++;

                if(low[v] >= ids[u] && p != -1)
                    critical_points.insert(u);
            }
            else
                low[u] = min(low[u], ids[v]);
        }

        if(p == -1 && children > 1)
            critical_points.insert(u);
        return ret;
    }
};

class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {

        int R = grid.size(), C = grid[0].size();

        TarjanCriticalPoint cp(R * C);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                if(!grid[i][j]) continue;
                int u = i * C + j;

                if(j + 1 < C && grid[i][j + 1]) cp.add_edge(u, i * C + j + 1);
                if(i + 1 < R && grid[i + 1][j]) cp.add_edge(u, (i + 1) * C + j);
            }

        return !cp.solve() || !cp.get_critical_points().empty();
    }
};


int main() {

    return 0;
}
