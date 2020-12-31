/// Source : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
/// Author : liuyubobobo
/// Time   : 2019-05-04

#include <iostream>
#include <vector>

using namespace std;


/// Inorder Traversal and Store all values
/// Time Complexity: O(2n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    int index = 0;

public:
    TreeNode* bstToGst(TreeNode* root) {

        if(!root) return root;
        if(!root->left && !root->right) return root;

        vector<int> order;
        inorder(root, order);

        for(int i = order.size() - 2; i >= 0; i --)
            order[i] += order[i + 1];

        index = 0;
        go(root, order);
        return root;
    }

private:
    void inorder(TreeNode* root, vector<int>& order){

        if(root->left) inorder(root->left, order);
        order.push_back(root->val);
        if(root->right) inorder(root->right, order);
    }

    void go(TreeNode* root, const vector<int>& order){

        if(root->left) go(root->left, order);
        root->val = order[index ++];
        if(root->right) go(root->right, order);
    }
};


int main() {

    return 0;
}