/// Source : https://leetcode.cn/problems/KnLfVT/
/// Author : liuyubobobo
/// Time   : 2022-10-07

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
    TreeNode* expandBinaryTree(TreeNode* root) {

        return dfs(root);
    }

private:
    TreeNode* dfs(TreeNode* node){

        if(node->left){
            TreeNode* lnode = new TreeNode(-1, dfs(node->left), nullptr);
            node->left = lnode;
        }

        if(node->right){
            TreeNode* rnode = new TreeNode(-1, nullptr, dfs(node->right));
            node->right = rnode;
        }

        return node;
    }
};


int main() {

    return 0;
}
