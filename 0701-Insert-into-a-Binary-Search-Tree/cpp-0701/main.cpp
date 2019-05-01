/// Source : https://leetcode.com/problems/insert-into-a-binary-search-tree/
/// Author : liuyubobobo
/// Time   : 2019-04-30

#include <iostream>

using namespace std;


/// Recursive
/// Time Complexity: O(h)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(!root) return new TreeNode(val);

        if(val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};


int main() {

    return 0;
}