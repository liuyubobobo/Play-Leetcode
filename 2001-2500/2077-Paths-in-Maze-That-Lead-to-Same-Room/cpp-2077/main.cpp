/// Source : https://leetcode.com/problems/paths-in-maze-that-lead-to-same-room/
/// Author : liuyubobobo
/// Time   : 2021-11-19

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n + m)
/// Space Complexity: O(n^2)
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {

        vector<vector<bool>> M(n, vector<bool>(n, false));
        vector<vector<int>> g(n);
        vector<pair<int, int>> edges(corridors.size());
        for(int i = 0; i < corridors.size(); i ++){
            int a = corridors[i][0] - 1, b = corridors[i][1] - 1;
            M[a][b] = M[b][a] = true;
            g[a].push_back(b), g[b].push_back(a);
            edges[i] = {a, b};
        }

        int res = 0;
        for(const pair<int, int>& e: edges)
            for(int v: g[e.first])
                res += (v != e.second && M[v][e.second]);
        return res / 3;
    }
};


int main() {

    return 0;
}
