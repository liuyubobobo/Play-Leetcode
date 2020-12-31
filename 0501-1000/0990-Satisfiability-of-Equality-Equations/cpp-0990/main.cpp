/// Source : https://leetcode.com/problems/satisfiability-of-equality-equations/
/// Author : liuyubobobo
/// Time   : 2019-02-13

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS
/// Time Complexity: O(26^2 * n)
/// Space Complexity: O(26^2)
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        vector<unordered_set<int>> g(26);
        for(const string& e: equations)
            if(e[1] == '=')
                g[e[0] - 'a'].insert(e[3] - 'a'),
                g[e[3] - 'a'].insert(e[0] - 'a');

        for(const string& e: equations)
            if(e[1] == '!' && isConnected(g, e[0] - 'a', e[3] - 'a'))
                return false;
        return true;
    }

private:
    bool isConnected(const vector<unordered_set<int>>& g, int x, int y){

        vector<bool> visited(26, false);
        return dfs(g, x, y, visited);
    }

    bool dfs(const vector<unordered_set<int>>& g, int s, int t, vector<bool>& visited){

        visited[s] = true;
        if(s == t) return true;
        for(int next: g[s])
            if(!visited[next] && dfs(g, next, t, visited))
                return true;
        return false;
    }
};


int main() {

    return 0;
}