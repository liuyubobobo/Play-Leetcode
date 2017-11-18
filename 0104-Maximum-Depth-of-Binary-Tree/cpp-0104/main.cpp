/// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {

    return 0;
}