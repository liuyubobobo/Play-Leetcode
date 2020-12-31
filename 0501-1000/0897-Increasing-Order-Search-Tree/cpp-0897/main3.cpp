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


/// Inorder traversal and link during the traversal
/// Using a class member TreeNode cur:)
///
/// Time Complexity: O(n)
/// Space Complexity: O(h) where h is the height of the tree
class Solution {

private:
    TreeNode* cur;

public:
    TreeNode* increasingBST(TreeNode* root) {

        if(root == NULL)
            return NULL;

        TreeNode* dummyRoot = new TreeNode(-1);
        cur = dummyRoot;
        inOrder(root);

        TreeNode* ret = dummyRoot->right;
        delete dummyRoot;
        return ret;
    }

private:
    void inOrder(TreeNode* node){

        if(node == NULL)
            return;

        inOrder(node->left);

        cur->right = node;
        cur = cur->right;
        cur->left = NULL;

        inOrder(node->right);
    }
};


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    Solution().increasingBST(root);

    return 0;
}