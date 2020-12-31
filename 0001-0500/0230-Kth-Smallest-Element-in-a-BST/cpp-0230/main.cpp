/// Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
/// Author : liuyubobobo
/// Time   : 2018-07-29
#include <iostream>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Inorder Traversal
/// Time Complexity: O(n)
/// Space Complexity: O(h) where h is the height of the BST
class Solution {

private:
    int index;

public:
    int kthSmallest(TreeNode* root, int k) {
        index = 0;
        return kthSmallestNode(root, k)->val;
    }

private:
    TreeNode* kthSmallestNode(TreeNode* node, int k){

        if(node == NULL)
            return NULL;

        TreeNode* res = kthSmallestNode(node->left, k);
        if(res) return res;

        index ++;
        if(index == k)
            return node;

        return kthSmallestNode(node->right, k);
    }
};


int main() {

    return 0;
}