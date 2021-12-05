/// Source : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
/// Author : liuyubobobo
/// Time   : 2021-12-04

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// BFS
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
    string getDirections(TreeNode* root, int s, int t) {

        int n = sz(root);

        vector<vector<pair<int, char>>> g(n + 1);
        dfs(root, g);

        vector<pair<int, char>> pre(n + 1, {-1, ' '});
        queue<int> q;
        q.push(s);
        pre[s] = {s, ' '};
        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(u == t) break;

            for(const pair<int, char>& p: g[u]){
                int v = p.first;
                if(pre[v].first == -1){
                    pre[v] = {u, p.second};
                    q.push(v);
                }
            }
        }

        string res = "";
        int cur = t;
        while(pre[cur].first != cur){
            res += pre[cur].second;
            cur = pre[cur].first;
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(TreeNode* node, vector<vector<pair<int, char>>>& g){

        if(!node) return;

        if(node->left){
            g[node->val].push_back({node->left->val, 'L'});
            g[node->left->val].push_back({node->val, 'U'});
        }
        if(node->right){
            g[node->val].push_back({node->right->val, 'R'});
            g[node->right->val].push_back({node->val, 'U'});
        }

        dfs(node->left, g);
        dfs(node->right, g);
    }

    int sz(TreeNode* node){

        if(!node) return 0;

        int res = 1;
        if(node->left) res += sz(node->left);
        if(node->right) res += sz(node->right);
        return res;
    }
};

int main() {

    TreeNode* left = new TreeNode(1, new TreeNode(3), nullptr);
    TreeNode* right = new TreeNode(2, new TreeNode(6), new TreeNode(4));
    TreeNode* root = new TreeNode(5, left, right);
    cout << Solution().getDirections(root, 3, 6) << endl;
    // UURL

    return 0;
}
