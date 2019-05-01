/// Source : https://leetcode.com/problems/delete-node-in-a-bst/
/// Author : liuyubobobo
/// Time   : 2019-04-30

#include <iostream>

using namespace std;


/// Recursion
/// Time Complexity: O(logn)
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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(!root)
            return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left, key);
            return root;
        }

        if(key > root->val){
            root->right = deleteNode(root->right, key);
            return root;
        }

        if(!root->right) return root->left;

        if(!root->left) return root->right;

        TreeNode* p = root, *minnode = root->right;
        while(minnode->left){
            p = minnode;
            minnode = minnode->left;
        }

        root->val = minnode->val;
        root->right = deleteMinNode(root->right);
        return root;
    }

private:
    TreeNode* deleteMinNode(TreeNode* root){

        if(!root->left) return root->right;
        root->left = deleteMinNode(root->left);
        return root;
    }
};


int main() {

    return 0;
}