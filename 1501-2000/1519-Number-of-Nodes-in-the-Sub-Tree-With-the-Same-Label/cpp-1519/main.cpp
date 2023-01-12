/// Source : https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
/// Author : liuyubobobo
/// Time   : 2023-01-12

#include <iostream>
#include <vector>
#include <list>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<list<int>> tree(n);
        for(const vector<int>& e: edges){
            int u = e[0], v = e[1];
            tree[u].push_back(v), tree[v].push_back(u);
        }

        vector<vector<int>> table(n, vector<int>(26, 0));
        dfs(tree, 0, -1, labels, table);

        vector<int> res(n);
        for(int i = 0; i < n; i ++)
            res[i] = table[i][labels[i] - 'a'];
        return res;
    }

private:
    void dfs(const vector<list<int>>& tree, int u, int p,
             const string& label, vector<vector<int>>& table){

        table[u][label[u] - 'a'] ++;
        for(int v: tree[u]){
            if(v == p) continue;
            dfs(tree, v, u, label, table);
            for(int i = 0; i < 26; i ++)
                table[u][i] += table[v][i];
        }
    }
};


int main() {

    return 0;
}
