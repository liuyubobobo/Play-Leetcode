/// Source : https://leetcode.com/problems/count-the-number-of-complete-components/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>
#include <list>

using namespace std;


/// Simulation
/// Time Complexity: O(n + m)
/// Space Complexity: O(n + m)
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<list<int>> g(n);
        for(auto& e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        vector<bool> visited(n, false);
        int res = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;

            vector<int> cc;
            dfs(g, i, visited, cc);
            res += ok(g, cc);
        }
        return res;
    }

private:
    bool ok(const vector<list<int>>& g, const vector<int>& cc){

        int d = cc.size() - 1;
        for(int u: cc)
            if(g[u].size() != d)
                return false;
        return true;
    }

    void dfs(const vector<list<int>>& g, int u, vector<bool>& visited, vector<int>& cc){

        visited[u] = true;
        cc.push_back(u);
        for(int v: g[u])
            if(!visited[v])
                dfs(g, v, visited, cc);
    }
};


int main() {

    return 0;
}
