/// Source : https://leetcode.com/problems/symmetric-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-06-02

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
/// Revert one child tree and see if the two child trees of the root are identical
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        right = revert(right);

        return is_identical(left, right);
    }

private:
    TreeNode* revert(TreeNode* root){
        if(root == NULL)
            return NULL;

        swap(root->left, root->right);
        revert(root->left);
        revert(root->right);
        return root;
    }

    bool is_identical(TreeNode* root1, TreeNode* root2){

        if(root1 == NULL && root2 == NULL)
            return true;

        if(root1 == NULL || root2 == NULL)
            return false;

        if(root1->val != root2->val)
            return false;

        return is_identical(root1->left, root2->left) &&
               is_identical(root1->right, root2->right);
    }
};


int main() {

    return 0;
}