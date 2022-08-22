/// Source : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
/// Author : liuyubobobo
/// Time   : 2022-08-20

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


/// DFS + BFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {

        vector<pair<int, int>> edges;
        dfs_edges(root, nullptr, edges);

        if(edges.empty()) return 0;

        int max_id = 0;
        for(const pair<int, int>& p: edges){
            max_id = max(max_id, p.first);
            max_id = max(max_id, p.second);
        }

        vector<list<int>> tree(max_id + 1);
        for(const pair<int, int>& p: edges){
            int u = p.first, v = p.second;
            tree[u].push_back(v), tree[v].push_back(u);
        }

        vector<int> dis(max_id + 1, -1);
        queue<int> q;
        q.push(start);
        dis[start] = 0;
        int res = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: tree[u]){
                if(dis[v] == -1){
                    q.push(v);
                    dis[v] = dis[u] + 1;
                    res = max(res, dis[v]);
                }
            }
        }
        return res;
    }

private:
    void dfs_edges(TreeNode* node, TreeNode* p, vector<pair<int, int>>& edges){

        if(p){
            edges.push_back({p->val, node->val});
        }

        if(node->left) dfs_edges(node->left, node, edges);
        if(node->right) dfs_edges(node->right, node, edges);
    }
};


int main() {

    return 0;
}
