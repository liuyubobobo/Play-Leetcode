/// Source : https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
/// Author : liuyubobobo
/// Time   : 2010-02-10

#include <iostream>
#include <cassert>

using namespace std;

/// Brute Force
/// For every node, find his prev and next node and compare the diff
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(logn)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {

        if(root == NULL)
            return INT_MAX;

        if(root->left == NULL && root->right == NULL)
            return INT_MAX;

        int diff1 = root->left ? root->val - maxInBST(root->left) : INT_MAX;
        int diff2 = root->right ? minInBST(root->right) - root->val : INT_MAX;

        return min(min(diff1, diff2),
                   min(minDiffInBST(root->left), minDiffInBST(root->right)));
    }

private:
    int maxInBST(TreeNode* node){
        assert(node != NULL);
        if(node->right)
            return maxInBST(node->right);
        return node->val;
    }

    int minInBST(TreeNode* node){
        assert(node != NULL);
        if(node->left)
            return minInBST(node->left);
        return node->val;
    }
};

int main() {

    // [90,69,null,49,89,null,52,null,null,null,null]

    return 0;
}