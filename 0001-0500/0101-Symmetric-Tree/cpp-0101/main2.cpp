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
/// No need to revert one child tree
/// See if the two child trees of the root are mirror directly
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        return is_mirror(root, root);
    }

private:
    bool is_mirror(TreeNode* root1, TreeNode* root2){

        if(root1 == NULL && root2 == NULL)
            return true;

        if(root1 == NULL || root2 == NULL)
            return false;

        if(root1->val != root2->val)
            return false;

        return is_mirror(root1->left, root2->right) &&
               is_mirror(root1->right, root2->left);
    }
};


int main() {

    return 0;
}