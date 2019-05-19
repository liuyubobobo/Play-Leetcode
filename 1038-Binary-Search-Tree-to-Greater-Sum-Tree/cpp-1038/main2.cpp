/// Source : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
/// Author : liuyubobobo
/// Time   : 2019-05-19

#include <iostream>
#include <vector>

using namespace std;


/// Inorder Traversal and Change the values during traversal
/// Using a class member pre
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    int pre = 0;

public:
    TreeNode* bstToGst(TreeNode* root) {

        if(!root) return root;

        if(root->right)
            bstToGst(root->right);

        pre += root->val;
        root->val = pre;

        if(root->left)
            bstToGst(root->left);

        return root;
    }
};


int main() {

    return 0;
}