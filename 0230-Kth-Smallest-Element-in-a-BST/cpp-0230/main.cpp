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
public:
    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        return kthSmallestNode(root, k, index)->val;
    }

private:
    TreeNode* kthSmallestNode(TreeNode* node, int k, int& index){

        if(node == NULL)
            return NULL;

        TreeNode* res = kthSmallestNode(node->left, k, index);
        if(res) return res;

        index ++;
        if(index == k)
            return node;

        return kthSmallestNode(node->right, k, index);
    }
};


int main() {

    return 0;
}