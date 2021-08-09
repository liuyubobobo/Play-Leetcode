/// Source : https://leetcode.com/problems/convert-bst-to-greater-tree/
/// Author : liuyubobobo
/// Updated: 2021-08-09

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

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
    TreeNode* convertBST(TreeNode* root) {

        pair<TreeNode*, int> res = dfs(root, 0);
        root = res.first;
        return res.first;
    }

private:
    pair<TreeNode*, int> dfs(TreeNode* node, int t){

        if(!node) return {nullptr, 0};

        pair<TreeNode*, int> rres = dfs(node->right, t);
        pair<TreeNode*, int> lres = dfs(node->left, node->val + rres.second + t);

        node->left = lres.first;
        node->right = rres.first;
        int sum = node->val + lres.second + rres.second;
        node->val += rres.second + t;

        return {node, sum};
    }
};


int main() {

    return 0;
}
