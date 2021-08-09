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

private:
    int sum = 0;

public:
    TreeNode* convertBST(TreeNode* root) {

        sum = 0;
        return dfs(root);
    }

private:
    TreeNode* dfs(TreeNode* node){

        if(!node) return node;

        node->right = dfs(node->right);
        sum += node->val;
        node->val = sum;
        node->left = dfs(node->left);

        return node;
    }
};


int main() {

    return 0;
}
