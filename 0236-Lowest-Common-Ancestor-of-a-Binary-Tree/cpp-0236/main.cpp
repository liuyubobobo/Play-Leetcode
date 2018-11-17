/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-01-30

#include <iostream>
#include <cassert>

using namespace std;

/// Recursion implementation
/// Time Complexity: O(n)
/// Space Complexity: O(n)

///Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 在root中寻找p和q
    // 如果p和q都在root所在的二叉树中, 则返回LCA
    // 如果p和q只有一个在root所在的二叉树中, 则返回p或者q
    // 如果p和q均不在root所在的二叉树中, 则返回NULL
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL)
            return root;

        if(root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL)
            return root;

        if(left != NULL)
            return left;

        if(right != NULL)
            return right;

        return NULL;
    }
};


int main() {

    return 0;
}