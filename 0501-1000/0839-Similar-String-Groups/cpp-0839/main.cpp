/// Source : https://leetcode.com/problems/similar-string-groups/solution/
/// Author : liuyubobobo
/// Time   : 2021-01-30

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS
/// Time Complexity: O(n^2 * |str|)
/// Space Complexity: O(n^2)
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {

        int n = strs.size();
        vector<unordered_set<int>> g(n);
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                if(similar(strs[i], strs[j]))
                    g[i].insert(j), g[j].insert(i);

        vector<bool> visited(n, false);
        int res = 0;
        for(int i = 0; i < n; i ++)
            if(!visited[i]){
                res ++;
                dfs(g, i, visited);
            }
        return res;
    }

private:
    void dfs(const vector<unordered_set<int>>& g, int u, vector<bool>& visited){

        visited[u] = true;
        for(int v: g.at(u))
            if(!visited[v])
                dfs(g, v, visited);
    }

    bool similar(string& a, string& b){

        if(a == b) return true;

        int i = -1, j = -1;
        for(int k = 0; k < a.size(); k ++)
            if(a[k] != b[k]){
                if(i == -1) i = k;
                else if(j == -1) j = k;
                else return false;
            }

        return a[i] == b[j] && a[j] == b[i];
    }
};


int main() {

    return 0;
}
