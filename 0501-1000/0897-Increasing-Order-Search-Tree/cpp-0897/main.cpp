/// Source : https://leetcode.com/problems/increasing-order-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-09-01

#include <iostream>
#include <vector>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Inorder traversal and store all the nodes
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {

        if(root == NULL)
            return NULL;

        vector<TreeNode*> nodes;
        inOrder(root, nodes);

        for(int i = 1; i < nodes.size(); i ++){
            nodes[i - 1]->left = NULL;
            nodes[i - 1]->right = nodes[i];
        }
        nodes.back()->left = nodes.back()->right = NULL;
        return nodes[0];
    }

private:
    void inOrder(TreeNode* node, vector<TreeNode*>& nodes){

        if(node == NULL)
            return;

        inOrder(node->left, nodes);
        nodes.push_back(node);
        inOrder(node->right, nodes);
    }
};


int main() {

    return 0;
}