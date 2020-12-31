/// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    int minDepth(TreeNode* root) {

        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 1;

        int ret = INT_MAX;
        if(root->left != NULL)
            ret = min(ret, 1 + minDepth(root->left));
        if(root->right != NULL)
            ret = min(ret, 1 + minDepth(root->right));
        return ret;
    }
};


int main() {

    return 0;
}