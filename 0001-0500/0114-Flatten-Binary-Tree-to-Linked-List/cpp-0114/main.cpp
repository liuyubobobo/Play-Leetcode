/// Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
/// Author : liuyubobobo
/// Time   : 2021-05-14

#include <iostream>
#include <vector>

using namespace std;


/// DFS
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
    void flatten(TreeNode* root) {

        if(!root) return;

        vector<TreeNode*> v;
        dfs(root, v);

        for(int i = 0; i + 1 < v.size(); i ++)
            v[i]->left = nullptr, v[i]->right = v[i + 1];

        v.back()->right = nullptr;
        root = v[0];
    }

private:
    void dfs(TreeNode* node, vector<TreeNode*>& v){

        if(!node) return;
        v.push_back(node);
        dfs(node->left, v);
        dfs(node->right, v);
    }
};


int main() {

    return 0;
}
