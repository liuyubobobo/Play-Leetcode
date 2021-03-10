/// Source : https://leetcode.com/problems/add-one-row-to-tree/
/// Author : liuyubobobo
/// Time   : 2021-03-09

#include <iostream>


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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {

        return dfs(root, v, d, true);
    }

private:
    TreeNode* dfs(TreeNode* node, int v, int d, bool left){

        if(d == 1){
            TreeNode* new_node = new TreeNode(v);
            if(left) new_node->left = node;
            else new_node->right = node;
            return new_node;
        }

        if(!node) return nullptr;

        node->left = dfs(node->left, v, d - 1, true);
        node->right = dfs(node->right, v, d - 1, false);
        return node;
    }
};


int main() {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(1));
    Solution().addOneRow(root, 1, 3);

    return 0;
}
