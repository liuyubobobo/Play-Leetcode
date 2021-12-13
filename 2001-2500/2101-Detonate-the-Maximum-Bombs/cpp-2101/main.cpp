/// Source : https://leetcode.com/problems/detonate-the-maximum-bombs/
/// Author : liuyubobobo
/// Time   : 2021-12-12

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();

        vector<vector<int>> g(n);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++){
                if(i == j) continue;
                if(dis_sq(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]) <= (long long)bombs[i][2] * bombs[i][2])
                    g[i].push_back(j);
            }

        int res = 1;
        for(int i = 0; i < n; i ++){
            vector<bool> visited(n, false);
            res = max(res, dfs(g, i, visited));
        }
        return res;
    }

private:
    int dfs(const vector<vector<int>>& g, int u, vector<bool>& visited){

        visited[u] = true;
        int res = 1;
        for(int v: g[u])
            if(!visited[v]) res += dfs(g, v, visited);
        return res;
    }

    long long dis_sq(long long x1, long long y1, long long x2, long long y2){
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
};


int main() {

    return 0;
}
