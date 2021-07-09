/// Source : https://leetcode.com/problems/merge-two-binary-trees/
/// Author : liuyubobobo
/// Time   : 2021-07-09

#include <iostream>

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        return build(root1, root2);
    }

private:
    TreeNode* build(TreeNode* node1, TreeNode* node2){

        if(!node1 && !node2) return nullptr;

        TreeNode* node = new TreeNode((node1 ? node1->val : 0) + (node2 ? node2->val : 0));
        node->left = build((node1 ? node1->left : nullptr), (node2 ? node2->left : nullptr));
        node->right = build((node1 ? node1->right : nullptr), (node2 ? node2->right : nullptr));
        return node;
    }
};


int main() {

    return 0;
}
