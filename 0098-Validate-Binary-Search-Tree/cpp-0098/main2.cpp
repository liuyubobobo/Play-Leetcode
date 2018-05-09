/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-09

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

/// Recursive test
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        return isValidBST(root, INT_MIN, INT_MAX);
    }

private:
    bool isValidBST(TreeNode* node, int min, int max){

        if(node == NULL)
            return true;

        if(node->val < min || node->val > max)
            return false;

        if(node->left != NULL && node->left->val >= node->val)
            return false;

        if(node->right != NULL && node->right->val <= node->val)
            return false;

        return isValidBST(node->left, min, node->val - 1) && isValidBST(node->right, node->val + 1, max);
    }
};

int main() {

    return 0;
}