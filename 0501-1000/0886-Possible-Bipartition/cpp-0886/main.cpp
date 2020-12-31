/// Source : https://leetcode.com/problems/possible-bipartition/description/
/// Author : liuyubobobo
/// Time   : 2017-08-12

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS with Node-coloring
/// Time Complexity: O(N + E)
/// Space Complexity: O(N + E)
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {

        vector<unordered_set<int>> g(N);
        for(const vector<int>& p: dislikes){
            g[p[0] - 1].insert(p[1] - 1);
            g[p[1] - 1].insert(p[0] - 1);
        }

        vector<int> color(N, -1);
        for(int i = 0; i < N; i ++)
            if(color[i] == -1 && !dfs(g, i, 0, color))
                return false;
        return true;
    }

private:
    bool dfs(const vector<unordered_set<int>>& g, int u, int c,
             vector<int>& colors){

        if(colors[u] != -1)
            return colors[u] == c;

        colors[u] = c;
        for(int next: g[u])
            if(!dfs(g, next, 1 - c, colors))
                return false;
        return true;
    }
};


void print_bool(bool res){
    cout << (res ? "true" : "false") << endl;
}

int main() {

    vector<vector<int>> dislikes1 = {{1, 2}, {1, 3}, {2, 4}};
    print_bool(Solution().possibleBipartition(4, dislikes1));

    return 0;
}