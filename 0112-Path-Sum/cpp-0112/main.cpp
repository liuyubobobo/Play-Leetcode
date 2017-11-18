/// Source : https://leetcode.com/problems/path-sum/description/
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
/// Time Complexity: O(n), where n is the nodes' number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        if(root == NULL)
            return false;

        if(root->left == NULL && root->right == NULL)
            return sum == root->val;

        return hasPathSum(root->left, sum - root->val)
                || hasPathSum(root->right, sum - root->val);
    }
};

int main() {

    return 0;
}