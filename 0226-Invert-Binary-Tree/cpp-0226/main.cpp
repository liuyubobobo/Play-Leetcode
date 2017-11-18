/// Source : https://leetcode.com/problems/invert-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

#include <iostream>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Recursive
/// Time Complexity: O(n), where n is the node's number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL)
            return NULL;

        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);

        return root;
    }
};

int main() {

    return 0;
}